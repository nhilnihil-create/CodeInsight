#include <bits/stdc++.h>
using namespace std;

int disits(int x) {
  int ret = 0;
  while(x > 0) {
    ret += x%10;
    x /= 10;
  }
  return ret;
}

int main() {
  int n, ans = 100000;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a = i;
    int b = n-i;
    ans = min(ans, disits(a)+disits(b));
  }
  cout << ans << "\n";
}