#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  
  ll ans = 0;
  for(int d=40; d>=-1; d--){
    if(d!=-1 && !(k & (1LL<<d))) continue;
    
    ll tmp = 0;
    REPR(e,40){
      ll mask = 1LL<<e;
      int num = 0;
      REP(i,n) if(a[i] & mask) num++;
      
      if(e>d){
        if(k & mask) tmp += mask * (n-num);
        else tmp += mask * num;
      }else if(e==d){
        tmp += mask * num;
      }else{
        tmp += mask * max(num, n-num);
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}
