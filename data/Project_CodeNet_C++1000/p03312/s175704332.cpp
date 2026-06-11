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
  int N;
  cin >> N;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  vector<lint> S(N+1);
  REP(i, N) S[i+1] = S[i] + A[i];
  lint ans = 1e15;
  FOR(i, 2, N-1) {
    int l = 0;
    int r = i;
    while(r-l > 1) {
      int m = (l+r) / 2;
      if(S[m] >= S[i] - S[m]) {
        r = m;
      } else {
        l = m;
      }
    }
    lint ma = S[r];
    lint mi = S[i] - S[r]; 
    if(r != 0 && S[i]-S[r-1]*2 < ma - mi ) {
      ma = S[i] - S[r-1];
      mi = S[r-1];
    }

    l = i;
    r = N;
    while(r-l > 1) {
      int m = (l+r) / 2;
      if(S[m] - S[i] >= S[N] - S[m]) {
        r = m;
      } else {
        l = m;
      }
    }
    if(S[N] - 2*S[r-1] + S[i] < 2*S[r] - S[i] - S[N]) {
      r--;
    }
    ma = max(max(ma, S[r] - S[i]), S[N] - S[r]);
    mi = min(min(mi, S[r] - S[i]), S[N] - S[r]);

    if(ma-mi < ans) ans = ma-mi;
    
  }
  cout << ans << endl;
}