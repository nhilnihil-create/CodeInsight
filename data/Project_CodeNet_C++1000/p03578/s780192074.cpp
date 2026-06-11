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

int main(){
  ll n;cin>>n;
  map<ll,ll> m;
  rep(i,0,n){
    ll d;cin>>d;
    m[d]++;
  }
  ll k;cin>>k;
  rep(i,0,k){
    ll t;cin>>t;
    if(m[t]==0){cout<<"NO"<<endl;return 0;}
    m[t]--;
  }
  cout<<"YES"<<endl;
}





