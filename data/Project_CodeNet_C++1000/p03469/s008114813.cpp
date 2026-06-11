#include <stdio.h>
int main()
{ 
    char b[20];
    scanf("%s", &b);
    b[3] = '8';
    printf("%s", b);
    
    return 0;
}