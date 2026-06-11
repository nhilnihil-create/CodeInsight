#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N, C;
map<int, vector<Pii>> chan;
map<int, vector<Pii>> newchan;
map<int, int> evu;
map<int, int> evd;

int main() {
  cin >> N >> C;
  rep(i, 0, N) {
    int s, t, c;
    cin >> s >> t >> c;
    chan[c].push_back(Pii(s, t));
  }

  for (auto e : chan) {
    sort(e.second.begin(), e.second.end());
    if (e.second.size() == 0) {
      continue;
    }

    int s = e.second[0].first;
    int t = e.second[0].second;
    for (int i = 1; i < e.second.size(); ++i) {
      if (t != e.second[i].first) {
        newchan[e.first].push_back(Pii(s, t));
        s = e.second[i].first;
        t = e.second[i].second;
      } else {
        t = e.second[i].second;
      }
    }
    newchan[e.first].push_back(Pii(s, t));
  }

  for (auto e : newchan) {
    for (auto v : e.second) {
      evu[v.first]++;
      evd[v.second]++;
    }
  }

  int ans = 0;
  int sum = 0;
  repe(i, 1, 100000) {
    sum += evu[i];
    chmax(ans, sum);
    sum -= evd[i];
    chmax(ans, sum);
  }
  cout << ans << endl;
}
