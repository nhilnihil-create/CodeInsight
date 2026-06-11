#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

ll gcd(ll m, ll n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

int main() {
  ll n,x;
  cin>>n>>x;
  vector<ll> y(n);
  rep(i,n){
    ll b;
    cin>>b;
    y[i]=abs(b-x);
  }
  ll ans=y[0];
  rep(i,n-1){
    ans=gcd(ans,y[i+1]);
  }
  cout<<ans<<endl;
}