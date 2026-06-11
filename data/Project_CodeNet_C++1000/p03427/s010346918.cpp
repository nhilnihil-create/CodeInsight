//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  string s=to_string(n);
  ll k=s.size();
  bool nine=true;
  ll ans=0;
  if(k==1){
    cout<<n<<endl;
    return 0;
  }
  rep(i,k){
    
    if(i!=0){
      if(s[i]!='9')nine=false;
      ans+=9;
    }
    else ans+=s[0]-'0'-1;
  }
  if(nine)ans++;
  cout<<ans<<endl;
}
    
    
  