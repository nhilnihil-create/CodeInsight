#include<stdio.h>
 
int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int count = 0;
  
  for(int i= 0; i <= n; i++) {
  	int sum = 0;
  	
    for(int j = i; j != 0; j /= 10) {
      sum += j % 10;
    }
  
    if(sum >= a && sum <= b) {
      count += i;
    }
  }
  
   printf("%d", count);
   
  return 0;
}