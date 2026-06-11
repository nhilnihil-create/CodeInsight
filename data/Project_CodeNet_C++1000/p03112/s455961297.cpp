#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size())
const int INF=INT_MAX;
vvll con(15,vll(15,-1));//con[i][j]=人iが人jを正直/不親切と思っている

int main(){
  ll a,b,q;
  cin>>a>>b>>q;
  vll s(a),t(b);
  rep(i,0,a){
    cin>>s[i];
  }
  rep(i,0,b){
    cin>>t[i];
  }
  rep(i,0,q){
    ll x;
    cin>>x;
    auto its=lower_bound(s.begin(),s.end(),x),itt=lower_bound(t.begin(),t.end(),x);
    ll sb=*(its-1),se=*its,tb=*(itt-1),te=*itt;
    ll ans=1e15;
    if(its!=s.begin()&&itt!=t.begin()){ans=min(ans,max(x-sb,x-tb));}
    if(its!=s.end()&&itt!=t.end()){ans=min(ans,max(se-x,te-x));}
    if(its!=s.begin()&&itt!=t.end()){ans=min(ans,x-sb+(te-x)*2);ans=min(ans,(x-sb)*2+te-x);}
    if(its!=s.end()&&itt!=t.begin()){ans=min(ans,x-tb+(se-x)*2);ans=min(ans,(x-tb)*2+se-x);}
    cout<<ans<<endl;
  }
}