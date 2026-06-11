#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
char c[5] = {'M', 'A', 'R', 'C', 'H'};
int main() {
  int N;
  cin >> N;
  ll cnt = 0;
  unordered_map<char, ll> mp{};
  REP(i, N) {
    string s;
    cin >> s;
    if (s[0] != 'M' && s[0] != 'A' && s[0] != 'R' && s[0] != 'C' &&
        s[0] != 'H') {
      continue;
    }
    mp[s[0]]++;
  }
  ll ans = 0;
  /*for (auto s : mp) {
    for (auto t : mp) {
      for (auto u : mp) {
        if (s.first == t.first || t.first == u.first || u.first == s.first)
          continue;
        if (s.second == 0 || t.second == 0 || u.second == 0) continue;
        ans += s.second * t.second * u.second;
      }
    }
  }*/
  REP(i, 3) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += mp[c[i]] * mp[c[j]] * mp[c[k]];
      }
    }
  }
  cout << ans << endl;
}