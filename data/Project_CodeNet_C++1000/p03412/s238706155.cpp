#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  LL n;
  cin >> n;
  vector<LL> a(n),b(n);
  for(auto &x:a) cin >> x;
  for(auto &x:b) cin >> x;
  LL answer = 0;
  REP(i,30) {
    LL d = (1<<i);
    LL mask = d*2-1;
    vector<LL> xa(n),xb(n);
    REP(i,n) {
      xa[i] = (a[i] & mask);
      xb[i] = (b[i] & mask);
    }
    sort(xa.begin(),xa.end());
    LL tmp = 0;
    for(auto x:xb) {
      tmp += lower_bound(xa.begin(),xa.end(),d*4-x) -
        lower_bound(xa.begin(),xa.end(),d*3-x);
      tmp += lower_bound(xa.begin(),xa.end(),d*2-x) -
        lower_bound(xa.begin(),xa.end(),d-x);
    }
    if(tmp%2) answer += d;
  }
  cout << answer << endl;
  return 0;
}
