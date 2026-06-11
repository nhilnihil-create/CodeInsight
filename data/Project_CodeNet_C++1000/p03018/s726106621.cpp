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
  string s;cin>>s;
  ll n=s.size(),ans=0;
  string t="";
  if(n<3){
    cout<<0<<endl;return 0;
  }
  rep(i,0,n-1){
    if(s[i]=='B'&&s[i+1]=='C'){
      t+="Z";
      i++;
    }
    else t+=s[i];
  }
  ll m=t.size();
  ll cnt=0;
  rep(i,0,m){
    if(t[i]=='Z')ans+=cnt;
    else if(t[i]=='A')cnt++;
    else cnt=0;
  }
  cout<<ans<<endl;
}

