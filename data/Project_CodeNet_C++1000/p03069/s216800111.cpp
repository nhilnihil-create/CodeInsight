#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> black(n + 1), white(n + 1);
  rep(i, n) {
    black[i + 1] = black[i] + (s[i] == '#');
    white[i + 1] = white[i] + (s[i] == '.');
  }

  int ans = INF;
  rep(i, n + 1) ans = min(ans, black[i] + white[n] - white[i]);
  cout << ans << endl;
  return 0;
}
