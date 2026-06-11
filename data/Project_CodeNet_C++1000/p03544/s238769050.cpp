#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  long long twoPrev = 2;
  long long prev = 1;
  
  long long ans = 1;
  for(int i = 2; i <= n; i++) {
    ans = prev + twoPrev;
    twoPrev = prev;
    prev = ans;
  }
  
  cout << ans << endl;

  return 0;
}