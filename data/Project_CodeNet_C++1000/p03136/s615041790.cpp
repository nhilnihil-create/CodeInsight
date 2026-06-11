#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  
  int sum = 0;
  int max = 0;
  for( int i = 0; i < n; ++i ) { 
    int v = 0;
    scanf("%d", &v);
    max = max >= v ? max : v;
    sum += v;
  }
  if( max < (sum - max) ) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}