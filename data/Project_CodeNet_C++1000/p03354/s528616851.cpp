#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
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
int N, M;
int p[101010];
int x[101010], y[101010];
vector<int> G[101010];
bool used[101010];

void dfs(vector<int>& indexes, set<int>& values, int pos) {
  if (used[pos]) return;

  indexes.push_back(pos);
  values.insert(p[pos]);
  used[pos] = true;

  for (auto e : G[pos]) {
    dfs(indexes, values, e);
  }
}

int main() {
  cin >> N >> M;
  repe(i, 1, N) { cin >> p[i]; }
  repe(i, 1, M) {
    cin >> x[i] >> y[i];
    G[x[i]].push_back(y[i]);
    G[y[i]].push_back(x[i]);
  }

  ll ans = 0;
  repe(i, 1, N) {
    if (used[i]) continue;

    vector<int> indexes;
    set<int> values;
    dfs(indexes, values, i);

    for (auto i : indexes) {
      if (values.count(i) == 1) {
        ++ans;
      }
    }
  }

  cout << ans << endl;
}
