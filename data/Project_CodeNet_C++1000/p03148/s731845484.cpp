#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, K;
  cin >> N >> K;
  vector<P> A(N);
  REP(i, N) {
    lint t, d;
    cin >> t >> d;
    A[i] = make_pair(d, t);
  }
  sort(ALL(A), greater<P>());
  lint dsum = 0;
  vector<lint> tnum(N+1);
  REP(i, K) {
    dsum += A[i].first;
    tnum[A[i].second]++;
  }
  lint tcnt = 0;
  REP(i, N+1) if(tnum[i] > 0) tcnt++;
  int lidx = K-1;
  int ridx = K;
  lint ans = dsum + tcnt*tcnt;
  while(lidx >= 0 && ridx < N) {
    if(tnum[A[lidx].second] == 1) {
      lidx--;
      continue;
    }
    if(tnum[A[ridx].second] > 0) {
      ridx++;
      continue;
    }
    tnum[A[lidx].second]--;
    tnum[A[ridx].second]++;
    dsum += A[ridx].first - A[lidx].first;
    tcnt++;
    if(dsum + tcnt*tcnt > ans) ans = dsum + tcnt*tcnt;
    lidx--;
    ridx++;
  }

  cout << ans << endl;

}