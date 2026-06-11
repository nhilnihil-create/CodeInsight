#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  ll cost = 0, cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'W') {
      cost += i - cnt;
      cnt++;
    }
  }
  cout << cost << endl;
  return 0;
}
