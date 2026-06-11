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
typedef tuple<ll,ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll a,b,q;cin>>a>>b>>q;
  vl s(a),t(b),x(q);
  rep(i,a)cin>>s[i];
  rep(i,b)cin>>t[i];
  rep(i,q)cin>>x[i];
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  rep(i,q){
    ll idx_lowers=a;
    ll idx_lowert=b;
    if(s[a-1]>=x[i]){
      idx_lowers= distance(s.begin(),lower_bound(s.begin(), s.end(), x[i]) );
    }
    if(t[b-1]>=x[i]){
      idx_lowert= distance(t.begin(),lower_bound(t.begin(),t.end(),x[i]) );
    }
    vl ans;
    //cout<<idx_lowers<<" "<<idx_lowert;
    //cout<<endl;
    if(idx_lowers!=a&&idx_lowert!=b)ans.push_back(max(s[idx_lowers]-x[i],t[idx_lowert]-x[i]));
    if(idx_lowers>=1&&idx_lowert>=1)ans.push_back(max(x[i]-s[idx_lowers-1],x[i]-t[idx_lowert-1]));
    if(idx_lowers>=1&&idx_lowert!=b)ans.push_back(min(x[i]-s[idx_lowers-1]+(t[idx_lowert]-x[i])*2,(x[i]-s[idx_lowers-1])*2+t[idx_lowert]-x[i]));
    if(idx_lowers!=a&&idx_lowert>=1)ans.push_back(min(x[i]-t[idx_lowert-1]+(s[idx_lowers]-x[i])*2,(x[i]-t[idx_lowert-1])*2+s[idx_lowers]-x[i]));
    sort(ans.begin(),ans.end());
    //rep(j,ans.size())cout<<ans[j]<<" ";
    //cout<<endl;
    cout<<ans[0]<<endl;
  }
}
  