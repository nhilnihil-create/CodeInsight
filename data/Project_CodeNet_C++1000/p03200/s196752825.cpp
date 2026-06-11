#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
int f(ll i,vll a){
  if(a[i]<a[i+1])return 1;
  else if(a[i]==a[i+1])return 2;
  else return 3;
}
int main(){
  string s;cin>>s;
  ll cnt=0,ans=0;
  rep(i,0,s.size()){
    if(s[i]=='B')cnt++;
    else ans+=cnt;
  }
  cout<<ans<<endl;
}
