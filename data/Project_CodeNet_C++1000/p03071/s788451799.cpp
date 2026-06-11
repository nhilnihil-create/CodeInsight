#include<stdio.h>
int main()
 {
     int a,b;
     scanf("%d %d", &a, &b);
     if(a==b)
        printf("%d", 2*a);
     else if(a>b)
        printf("%d", 2*a-1);
     else
        printf("%d", 2*b-1);
 
     return 0;
 }