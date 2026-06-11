#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  scanf("%d", &N);
  printf("%d\n", (N % 2 == 0) ? N : (2 * N));
  return 0;
}