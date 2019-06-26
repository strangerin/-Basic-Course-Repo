#include<stdio.h>
//условно большие числа, должны быть в рамках установленого размера массива
//нет проверок на число/не число - возможная уязвимость
//так как логика через ASCII (0-48) не будет работать с отрицательными значениями
int main() {
    int num1[255], num2[255], sum[255];// сохраняем БОЛЬШИЕ числа в массивы, потому что в обычные типы они просто не влезут как я понял
    char s1[255], s2[255];
    int l1, l2;

    printf("Enter Number1:");
    scanf("%s", &s1);
    printf("Enter Number2:");
    scanf("%s", &s2);

    /* вот в этом куске конвертим char в int
    От каждой введённой цифры с клавиатуры удаляем 48 - получаем нужное число и обрабатываем по-одному. Примерно как операции "в столбик"
    
    */

    for (l1 = 0; s1[l1] != '\0'; l1++)
    num1[l1] = s1[l1] - '0';

    for (l2 = 0; s2[l2] != '\0'; l2++)
    num2[l2] = s2[l2] - '0';

    int carry = 0;
    int k = 0;
    int i = l1 - 1;
    int j = l2 - 1;
    
    // весь этот шматок немного замороченый - нужно было понимать что мы отрабатываем 3 сценария 1)одинаковое количество элементов в обеих числах, 2) 1>2, 3) 1<2
    for (; i >= 0 && j >= 0; i--, j--, k++) {
    sum[k] = (num1[i] + num2[j] + carry) % 10;
    carry = (num1[i] + num2[j] + carry) / 10;
    }
        if (l1 > l2) {

            while (i >= 0) {
            sum[k++] = (num1[i] + carry) % 10;
            carry = (num1[i--] + carry) / 10;
            }

        } else if (l1 < l2) {
            while (j >= 0) {
            sum[k++] = (num2[j] + carry) % 10;
            carry = (num2[j--] + carry) / 10;
            }
    
    } else {
    if (carry > 0)
    sum[k++] = carry;
    }


    printf("Result:\n");
    for (k--; k >= 0; k--)
    printf("%d", sum[k]);

return 0;

}