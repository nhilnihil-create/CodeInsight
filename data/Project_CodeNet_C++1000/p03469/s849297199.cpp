#include <stdio.h>
 
int main()

{
    char salahtahun[11];
    
    scanf("%s", salahtahun);
    salahtahun[3] = '8';
    printf("%s\n", salahtahun);
 
    return 0;
}