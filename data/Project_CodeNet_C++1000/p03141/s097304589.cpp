#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
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
/* clang-format on */


int main() {
  ll n,ans=0;
  cin >> n;
  priority_queue<pair<ll,ll>> q;
  vector<ll> a(n), b(n);
  REP(i, n) {
    cin >> a[i] >> b[i];
    q.push({a[i] + b[i],i});
  }

  while (true) {
    if (q.empty()) break;
    ans += a[q.top().second];
    q.pop();
    if (q.empty()) break;
    ans -= b[q.top().second];
    q.pop();
  }
  cout << ans << endl;
  
  return 0;
}
