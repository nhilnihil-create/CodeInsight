#include <stdio.h>
 
int main(){
 int a, b;
 scanf("%d %d", &a, &b);
 printf("%c\n", (a * b == 15)? '*':((a + b == 15)? '+': 'x'));
 return 0;
}