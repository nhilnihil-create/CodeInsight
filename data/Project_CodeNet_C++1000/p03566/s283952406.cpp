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
  vector<int> t(N);
  int tsum;
  REP(i, N) {
    cin >> t[i];
    tsum += t[i];
  }
  vector<int> v(N);
  REP(i, N) cin >> v[i];
  vector<int> vmax(tsum);
  int idx = 0;
  REP(i, N) REP(j, t[i]) {
    vmax[idx] = v[i];
    idx++;
  }
  vector<int> vmaxp(tsum+1);
  FOR(i, 1, tsum) vmaxp[i] = min(vmax[i-1], vmax[i]);
  vector<int> v1(tsum+1);
  FOR(i, 1, tsum+1) v1[i] = min(v1[i-1]+1, vmaxp[i]);
  vector<int> v2(tsum+1);
  IFOR(i, 1, tsum) v2[i] = min(v2[i+1]+1, vmaxp[i]);
  double ans = 0;
  REP(i, tsum) {
    double min1 = min(v1[i], v2[i]);
    double min2 = min(v1[i+1], v2[i+1]);
    if(min1 == min2 && vmax[i] > min1) {
      ans += min1 + 0.25;
    } else {
      ans += (min1 + min2) / 2.0;
    }
  }
  cout << setprecision(10) << ans << endl;
}