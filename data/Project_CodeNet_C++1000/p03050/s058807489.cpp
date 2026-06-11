#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
 /*約数列挙アルゴリズム*/
vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      //ret.push_back(i);
      ll a = n/i;
      if(a>i+1) ret.push_back(n / i-1);
    }
  }
  return (ret);
}


int main(void){
    ll n;
    cin>>n;
    vector<ll> v=divisor(n);
    ll ans=accumulate(v.begin(), v.end(), 0LL);
    cout<<ans<<endl;
    return 0;
}