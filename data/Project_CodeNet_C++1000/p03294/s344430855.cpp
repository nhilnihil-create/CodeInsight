#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
ll lcm(int a, int b){
  int c=__gcd(a,b);
  c=a/c*b;
  return c;
}

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  /////
  ll ans=0;
  rep(i,n){
    ans+=(a[i]-1);
  }
  cout<<ans<<endl;
}