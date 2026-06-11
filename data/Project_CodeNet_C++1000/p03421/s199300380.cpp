#include <cstdio>
#include<iostream>
using namespace std;
int main(){
  int N, A, B; scanf("%d%d%d", &N, &A, &B);
  if(A + B - 1 > N || N > 1LL * A * B){ puts("-1"); return 0; } 
  for(int l = 0, g = N - A, a = 1; a <= A; a++){
    int t =(g > B - 1)? B - 1 : g;
    for(int i = l + t + 1; i > l; i--) 
		printf("%d ", i);
    l += t + 1; g -= t;
  }
   printf("\n");
  return 0;
}
