#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const ll inf = 1LL << 60;
 
signed main(void){ 

  ll N; cin >> N;
  ll sum = 0; ll m = inf;
  for(ll i = 0; i < N; i++){ 
    ll a,b; cin >> a >> b; sum += a; 
    if ( a > b ){ m = min(m,b);}
  }
  
  if( m == inf ){ //この時、 A==Bに他ならない　
    cout << 0 << endl; return 0;
  }
  
  cout << sum-m << endl;
  
  return 0;
}
