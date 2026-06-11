#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll gcd(ll m, ll n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

int main() {
  ll n,x;
  cin>>n>>x;
  vector<ll> a(n);
  rep(i,n){
    ll A;
    cin>>A;
    a[i]=abs(A-x);
  }
  ll ans=a[0];
  rep(i,n-1){
    ans=gcd(ans,a[i+1]);
  }
  cout<<ans<<endl;
}