#include <stdio.h>

int main(){

    int length;
    int lowercase;

    scanf("%d %d", &length, &lowercase);
    char kata[length];
    scanf("%s", kata);
    kata[lowercase-1]+=32;
    printf("%s", kata);

    return 0;
}