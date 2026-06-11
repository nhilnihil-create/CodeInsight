#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int checked[100];
vector<vector<int>> A(0, vector<int>(0));
vector<P> T(0);
int N, M;
void dfs(int l,int ng,int before) {
  checked[l] = 1;
  REP(i, A[l].size()) {
    int a = A[l][i], b = l;
    if((a==T[ng].first&&b==T[ng].second)||(b==T[ng].first&&a==T[ng].second)){
      continue;
    }
    if (checked[a] == 1||a==before) continue;
    dfs(a, ng,l);
   }
}
int main() {
  cin >> N >> M;
  A.resize(N);
  T.resize(M);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    A[a].push_back(b);
    A[b].push_back(a);
    T[i] = P(a, b);
  }
  ll ans = 0;
  REP(i, M) {
    dfs(0,i,-1);
    bool t = true;
    REP(i, N) {
      if (checked[i] != 1) {
        t = false;
        break;
      }
    }
    if (!t) ans++;
    REP(i, N) checked[i] = 0;
  }
  cout << ans << endl;
}