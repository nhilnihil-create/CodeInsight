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

int main(){
  
  string s;cin>>s;
  vb c(26,true);
  rep(i,0,s.size()){
    c[s[i]-'a']=false;
  }
  rep(i,0,26){
    if(c[i]){
      s+=('a'+i);
      cout<<s<<endl;return 0;
    }
  }
  drep(i,s.size()-1,0){
    c[s[i]-'a']=true;
    rep(j,s[i]-'a'+1,26){
      if(c[j]){
        string t=s.substr(0,i);
        t+=('a'+j);
        cout<<t<<endl;return 0;
      }
    }
  }
  cout<<-1<<endl;
}
