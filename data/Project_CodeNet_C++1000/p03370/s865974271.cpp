#include <stdio.h>
#include <math.h>
int main() 
{
 int n,i,x,m; 
 scanf("%d %d",&n,&x); 
 int min = 1001; 
 for (i = 0; i < n; i++)
 { 
   scanf("%d", &m); 
   x -= m;
   min = (m < min ? m : min); 
 }
   printf("%d",n + (x / min));
 return 0;
}

    
    

 