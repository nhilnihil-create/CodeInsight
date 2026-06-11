#include<stdio.h>

int main() {
  
   int area;
   int base;
   int height;
   
   scanf("%d", &base);
   scanf("%d", &height);
   area = base*height/2;
   printf("%d", area);

   return 0;
}