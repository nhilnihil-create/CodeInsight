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

ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
   else{
       return(gcd(b, a%b));
    }
}
ll lcm(ll a,ll b){
   return (a / gcd(a, b))*b;
}
int main(){
  ll n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  ll ans=lcm(n,m);
  ll a=ans/n,b=ans/m;
  rep(i,0,gcd(n,m)){
    if(s[i*b]!=t[i*a]){
      cout<<-1<<endl;return 0;
    }
  }
  cout<<ans<<endl;
}
