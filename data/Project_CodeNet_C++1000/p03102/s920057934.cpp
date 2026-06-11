#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  int n, m, c, ans = 0;
  cin >> n >> m >> c;
  int a[n][m], b[m];
  REP(i, m) { cin >> b[i]; }
  REP(i, n) {
    REP(j, m) { cin >> a[i][j]; }
  }
  REP(i,n){
    int tmp = 0;
    REP(j, m) { tmp += a[i][j] * b[j]; }
    if (tmp + c > 0) ans++;
  }
  cout << ans << "\n";
  return 0;
}
