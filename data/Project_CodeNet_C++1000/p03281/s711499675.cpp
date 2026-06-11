#include <bits/stdc++.h>
using namespace std;

int num_of_div(int n) {
  int res = 0;
  
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      res++;
      continue;
    }
    
    if (n % i == 0) res += 2;
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  
  int ans = 0;
  for (int i = 1; i <= N; i += 2) {
    if (num_of_div(i) == 8) ans++;
  }
  
  cout << ans << endl;
}