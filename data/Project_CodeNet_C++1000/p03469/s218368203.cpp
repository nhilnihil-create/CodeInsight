#include<stdio.h>
int main(){
    char input[100];
    scanf("%s",&input);
    input[3]++;
    printf("%s\n",input);
    return 0;
}