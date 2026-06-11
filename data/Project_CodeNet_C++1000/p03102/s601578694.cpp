#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M,C;
  cin >> N >> M >> C;
  int A[N][M],B[M];
  REP(i,M) {
    cin >> B[i];
  }
  REP(i,N) {
    REP(j,M) {
      cin >> A[i][j];
    }
  }

  int ans = 0;
  REP(i,N) {
    int sum = 0;
    REP(j,M) {
      sum += A[i][j] * B[j];
    }
    if (sum + C > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}
