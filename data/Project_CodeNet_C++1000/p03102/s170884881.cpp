#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N, M, C;
  cin >> N >> M >> C;
  int ans = 0;
  vector<int> b(M);
  vector<vector<int>> a(N, vector<int>(M));
  REP(i, M) {
    cin >> b[i];
  }
  REP(i, N) {
    REP(j, M) {
      cin >> a[i][j];
    }
  }
  REP(i, N) {
    int tmp = C;
    REP(j, M) {
      tmp += a[i][j]*b[j];
    }
    if (tmp > 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}