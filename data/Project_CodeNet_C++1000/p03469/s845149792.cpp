#include <stdio.h>

int main(){

    char x[11];
    scanf("%s", x);
    x[0] = '2';
    x[1] = '0';
    x[2] = '1';
    x[3] = '8';
    printf("%s", x);

    return 0;
}