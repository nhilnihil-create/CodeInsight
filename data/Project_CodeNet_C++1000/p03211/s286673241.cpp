#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int ans = 999;
  rep(i, s.length()-2) {
    int num = (s[i] - '0')*100 + (s[i+1] - '0')*10 + s[i+2] - '0';
    ans = min(ans, abs(num - 753));
  }
  cout << ans << endl;
  return 0;
}