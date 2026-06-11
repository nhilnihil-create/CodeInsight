#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  ll n,c;
  cin>>n>>c;
  vector<P> v[c];
  rep(i,n){
    ll s1,t1,c1;
    cin>>s1>>t1>>c1;
    c1--;
    v[c1].push_back(make_pair(s1,t1));
  }
  vector<ll> C(100005,0);

  rep(i,c){
    //各チャンネルについて
    if (v[i].size()==0)continue;
    sort(v[i].begin(),v[i].end());
    ll now=-1;

    rep(j,v[i].size()){
      if (v[i][j].first>now){
        if (now>0)C[now]--;
        C[v[i][j].first-1]++;
        now=v[i][j].second;
      }
      else if (v[i][j].first==now){
        now=v[i][j].second;
      }
    }
    

    if (now>0)C[now]--;
  }

  ll ans=0;
  ll cnt=0;

  rep(i,100004){
    cnt+=C[i];
    ans=max(cnt,ans);
  }

  cout<<ans;

}
