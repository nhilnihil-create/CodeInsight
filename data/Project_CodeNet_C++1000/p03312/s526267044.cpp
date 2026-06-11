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
  vector<LL> a(n);
  for(auto &x:a) cin >> x;
  vector<LL> su(1);
  for(auto x:a) su.push_back(su.back()+x);
  LL answer = su[n];
  FOR(i,2,n-1) {
    LL p[2],q[2],r[2],s[2];
    auto lite = upper_bound(su.begin(),su.begin()+i,(su[i]+1)/2);
    p[0] = *lite;
    q[0] = su[i] - *lite;
    if(lite != su.begin()) --lite;
    p[1] = *lite;
    q[1] = su[i] - *lite;
    auto rite = upper_bound(su.begin()+i,su.begin()+n+1,(su[i]+su[n]+1)/2);
    if(rite == su.end()) --rite;
    r[0] = *rite - su[i];
    s[0] = su[n] - *rite;
    --rite;
    r[1] = *rite - su[i];
    s[1] = su[n] - *rite;
    REP(j,2) REP(k,2) {
      LL tmp = 0;
      tmp = max(tmp, abs(p[j]-q[j]));
      tmp = max(tmp, abs(p[j]-r[k]));
      tmp = max(tmp, abs(p[j]-s[k]));
      tmp = max(tmp, abs(q[j]-r[k]));
      tmp = max(tmp, abs(q[j]-s[k]));
      tmp = max(tmp, abs(r[k]-s[k]));
      answer = min(answer, tmp);
    }
  }
  cout << answer << endl;
  return 0;
}
