#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  string ans = "";
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (n) {
    if (n % 2) {
      ans += '1';
      n--;
    } else {
      ans += '0';
    }
    n /= (-2);
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}