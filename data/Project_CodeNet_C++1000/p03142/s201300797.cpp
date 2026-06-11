#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

vector<int> g[101010];
int in[101010];

int main() {
  int n, m;
  cin >> n >> m;
  REP(i, n - 1 + m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    in[b]++;
  }
  queue<int> que;
  REP(i, n) {
    if (in[i] == 0) que.push(i);
  }
  int ans[n];
  REP(i, n) ans[i] = -1;
  while (que.size()) {
    int p = que.front();
    que.pop();
    REP(i, g[p].size()) {
      int q = g[p][i];
      in[q]--;
      if (in[q] == 0) {
        que.push(q);
        ans[q] = p;
      }
    }
  }
  REP(i, n) cout << ans[i] + 1 << endl;
  return 0;
}