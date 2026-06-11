#include <bits/stdc++.h>
using namespace std;
int be = 1900, af = 100;
int main(){
  int n, m,sum = 0;
  scanf("%d %d", &n, &m);
  sum += be * m + af * (n-m);
  for(int i = 0; i < m; i++) sum *= 2;
  printf("%d", sum);
}