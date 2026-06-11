#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  ll count[5] = {};
  rep(i, n) {
    string s;
    cin >> s;
    if (s[0] == 'M') count[0]++;
    if (s[0] == 'A') count[1]++;
    if (s[0] == 'R') count[2]++;
    if (s[0] == 'C') count[3]++;
    if (s[0] == 'H') count[4]++;
  }
  ll ans = 0;
  //10通りのパターンを記述。
  int p[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
  int q[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
  int r[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
  rep(i, 10) ans += count[p[i]] * count[q[i]] * count[r[i]];
  cout << ans << endl;
  return 0;
}