#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

ll pow2(ll b) {ll ret=1;rep(i,b) ret*=2;return ret;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k,a,ans=0,s,t;cin>>n>>k;
  lvector digit(40,0),take_zero(40,0),max_(40,0),k_(40,0);
  rep(i,n) {
    cin>>a;
    rep(j,40) if((a>>j)&1) digit[j]++;
  }
  rep(i,40) {
    a=pow2(i);
    k_[i]+=((k>>i)&1)?(n-digit[i])*a:digit[i]*a;
    ans+=k_[i];
    take_zero[i]+=digit[i]*a;
    max_[i]+=max(digit[i],n-digit[i])*a;
  }
  rep(i,40) {
    if((k>>i)&1) {
      s=0,t=0;
      for(ll j=i+1;j<40;++j) s+=k_[j];
      for(ll j=0;j<i;++j) t+=max_[j];
      ans=max(ans,s+take_zero[i]+t);
    }
  }
  print(ans);
  return 0;
}