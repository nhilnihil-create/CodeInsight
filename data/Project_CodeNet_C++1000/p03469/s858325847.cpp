#include <stdio.h>

int main() 
{
    char s[12];

    scanf("%s", &s);

    s[3] = '8';
    printf("%s", s);
    
    return 0;
}