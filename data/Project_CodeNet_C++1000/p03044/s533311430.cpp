#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
const ll MOD = 1000000007;
struct edge {
  ll back;
  ll now;
  ll dis;
};
edge RetEd(ll a, ll b, ll c) {
  edge E;
  E.back = a;
  E.now = b;
  E.dis = c;
  return E;
}
int main() {
  int N;
  cin >> N;
  vector<vector<P>> A(N);
  REP(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    A[a].push_back(P(b, c));
    A[b].push_back(P(a, c));
  }
  vector<int> Ans(N, -1);
  REP(i, N) {
    if (Ans[i] != -1) continue;
    queue<edge> que;
    que.push(RetEd(-1, i, 0));
    while (!que.empty()) {
      edge e = que.front();
      que.pop();
      Ans[e.now] = e.dis % 2;
      for (auto s : A[e.now]) {
        if (s.first == e.back) continue;
        que.push(RetEd(e.now, s.first, s.second + e.dis));
      }
    }
  }
  REP(i, N) {
    cout << Ans[i];
    if (i != N - 1) {
      cout << " ";
    }
    cout << endl;
  }
}