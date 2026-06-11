#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
using P = pair<ll,ll>;
#define rep(i,n) for (ll i = 0; i<(ll)(n); i++)
#define mod 1000000007
#define pi 3.141592653589793
typedef vector<ll> vcl;

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t =rep_jijo(n,x/2);
        return t*t%mod;
  }
  return n*rep_jijo(n,x-1)%mod;
}
ll c2(ll n){
    return n*(n-1)/2;
}

int main() {
ll n;
cin>>n;
vcl a(n),cnt(n+1,1);
rep(i,n)cin>>a[i];

vcl s(n+1); 
for (ll i = 0; i < n; ++i) s[i+1] = s[i] + a[i];
sort(s.begin(), s.end());
ll j=0;
rep(i,n){
    if(s[i+1]==s[i])cnt[j]++;
    else j++;
}
ll ans=0;
rep(i,j+1)ans+=c2(cnt[i]);
cout<<ans<<endl;
return 0;
}

