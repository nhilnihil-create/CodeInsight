#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  ll sum = 0;
  ll mn = 1e10;
  REP(i,n) {
    ll a,b;
    cin>>a>>b;
    sum += a;
    if (a>b) {
      mn = min(mn, b);
    }
  }
  if (mn > 1e9) {
    cout<< 0<<endl;
  } else {
    cout << sum - mn << endl;
  }
  return 0;
}
