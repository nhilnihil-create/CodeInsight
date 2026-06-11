#include "bits/stdc++.h"
#include "math.h"
 
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
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;


int main(){
  ll n;cin>>n;
  ll ans=0,a=0,b=0,both=0;
  rep(i,0,n){
    string s;
    cin>>s;
    rep(j,0,s.size()-1){
      if(s.size()==1)break;
      if(s[j]=='A'&&s[j+1]=='B')ans++;
    }
    if(s[0]=='B'&&s[s.size()-1]=='A')both++;
    else if(s[s.size()-1]=='A')a++;
    else if(s[0]=='B')b++;
  }
  if(a==0&&b==0&&both!=0){
    cout<<ans+both-1<<endl;return 0;
  }
  cout<<ans+min(n-1,both+min(a,b))<<endl;
}


