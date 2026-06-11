#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);
vector<ll>b;
ll cnt(ll a){
  ll sum=0;
  for(auto x:b){
    if((a&x)==a)sum++;
  }
  return sum;
}
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  vector<ll>s(n+1);
  s[0]=0;
  rep(i,n){
    s[i+1]=s[i]+a[i];
  }
  rep(i,n){
    for(ll j=i;j>=0;j--){
      b.push_back(s[i+1]-s[j]);
    }
  }
  ll ans=0;
  for(int i=40;i>=0;i--){
    if(cnt(ans|(1ll<<i))>=k){
      ans|=(1ll<<i);
    }
  }
  cout << ans << endl;
  
}
