#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( ll i = 0;i < (ll) n;++i)

ll keta( ll num ){
  if( num/10 == 0 ) return 1;
  return 1 + keta(num/10);
}

ll rui( ll n,ll k ){
  if( k == 0 ) return 1;
  return n*rui(n,k-1);
}

ll func( ll num ){
  if( num/10 == 0 ) return num%10;
  return num%10 + func(num/10);
}

int main(){
  ll n;
  cin >> n;
  ll k = keta(n);
  for(ll i=1;i<=k-1;i++){
    ll j = n%(rui(10,i))/rui(10,i-1);
    if( j != 9 ){
      n -= (j+1)*rui(10,i-1);
    }
  }
  cout << func(n) << endl;
  return 0;
}