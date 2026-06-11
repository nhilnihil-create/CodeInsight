#include <stdio.h>

int main(void){
    char s[11];
    scanf("%s", s);
    s[3] = '0'+8;
    printf("%s\n", s);
    return 0;
}