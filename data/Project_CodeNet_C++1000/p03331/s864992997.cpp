//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int sum(int n) {
  string s = to_string(n);
  int sum = 0;
  rep(i, s.size()) {
    sum += s[i] - '0';
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  
  int ans = 1e6;
  for (int a = 1; a < n; a++) {
    int b = n - a;
    int digits = sum(a) + sum(b);
    ans = min(ans, digits);
  }
  cout << ans << endl;
  return 0;
}


