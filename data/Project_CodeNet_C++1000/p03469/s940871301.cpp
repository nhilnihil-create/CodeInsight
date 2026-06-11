#include <stdio.h>

int main(){

    char tanggalan[10];

    scanf("%s", tanggalan);
    tanggalan[3]='8';
    printf("%s", tanggalan);
    
    return 0;
}