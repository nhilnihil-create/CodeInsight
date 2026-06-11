#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> prime(55555 + 1, 1);
  int x = 2;
  while(x * x <= 55555) {
    for(int i = x * 2; i <= 55555; i += x) prime[i] = 0;
    do
      x++;
    while(!prime[x]);
  }
  int n, c = 0;
  scanf("%d", &n);
  for(int i = 2; i <= 55555; i++) {
    if(prime[i] && i % 5 == 1) printf("%d%c", i, ++c == n ? '\n' : ' ');
    if(c == n) return 0;
  }
}