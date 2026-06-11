#include<stdio.h>
 
int main(){
   int a, p;
   scanf("%d %d", &a, &p);
   
   int sum = a*3 + p;
   int answer = sum / 2;
 
   printf("%d\n", answer);
   return 0;
}