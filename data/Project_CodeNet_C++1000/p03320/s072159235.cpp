#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
 
using namespace std;
LL p = 1000000007ll;
 
LL dsum(LL x)
{
  if(x<10) return x;
  else return dsum(x/10) + x%10;
}
 
int main(void)
{
  LL k;
  cin >> k;
  LL tmp = 1;
  LL diff = 1;
  REP(i,k) {
    cout << tmp << endl;
    if(1.0*(tmp+diff)/dsum(tmp+diff) > diff) diff*=10;
    tmp += diff;
  }
  return 0;
}