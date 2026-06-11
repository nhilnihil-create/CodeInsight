#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
#define all(v) v.begin(),v.end()


ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t%mod;
    }
    return n*rep_jijo(n,x-1)%mod;
}
 
int main(){
  int n;
  ll h;
  cin >> n >> h;
  ll a_mx=-inf;
  ll ans=0;
  vector<ll>dam(n);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    a_mx=max(a,a_mx);
    dam[i]=b;
  }
  sort(all(dam));
  reverse(all(dam));
  int now=0;
  while(h>0){
    if(dam[now]>=a_mx){
      h-=dam[now];
      now++;
      ans++;
    }
    else{
      h-=a_mx;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
