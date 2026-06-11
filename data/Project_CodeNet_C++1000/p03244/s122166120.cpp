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
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  REP(i, n) cin >> v[i];
  map<int, int, greater<int>> um{}, um2{};
  REP(i, n) {
    um[v[i]]++;
    i++;
  }
  vector<P> vx1(0), vx2(0);
  int mx1 = -1, num1 = -1;
  for (auto s : um) {
    vx1.push_back(pair<int, int>{s.second, s.first});
    if (mx1 < s.second) {
      mx1 = s.second;
      num1 = s.first;
    }
  }
  REP(i, n) {
    i++;
    um2[v[i]]++;
  }
  int mx2 = -1, num2 = 0;
  for (auto s : um2) {
    vx2.push_back(pair<int, int>{s.second, s.first});
    if (mx2 < s.second) {
      mx2 = s.second;
      num2 = s.first;
    }
  }
  sort(vx1.begin(), vx1.end(), greater<pair<int, int>>());
  sort(vx2.begin(), vx2.end(), greater<pair<int, int>>());
  int ans = 0;
  ans += n / 2 - vx1[0].first;
  ans += n / 2 - vx2[0].first;
  if (vx1[0].second == vx2[0].second) {
    ans = n;
    if (vx1[1].first < vx2[1].first) {
      ans -= vx1[0].first + vx2[1].first;
    } else {
      ans -= vx2[0].first + vx1[1].first;
    }
    if (vx1.size() == 1 || vx2.size() == 1) {
      if (vx1.size() == 1) {
        ans = n / 2 - vx2[1].first;
      }
      if (vx2.size() == 1) {
        ans = n / 2 - vx1[1].first;
      }
      if (vx1.size() == 1 && vx2.size() == 1) {
        ans = n / 2;
      }
    }
  }
  cout << ans << endl;
}