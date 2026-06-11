
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;



int main() {
  ll n;
  cin>>n;
  vector<ll> w(n);
  vector<ll> s(n);
  vector<ll> v(n);
  vector<P> p(n);
  vector<ll> W(n);
  vector<ll> V(n);

  rep(i,n){
    ll w1,s1,v1;
    cin>>w1>>s1>>v1;
    w[i]=w1;
    v[i]=v1;
    s[i]=s1;
    p[i]=make_pair(s[i]+w[i],i);
  //  cout<<p[i].first<<" "<<p[i].second<<endl;
  }
  sort(p.begin(),p.end());

  ll dp[n+5][20005];
  rep(i,n+5)rep(j,20005)dp[i][j]=0;
  //iばんめまでエラんだとき重さwfの価値の最大
  rep(i,n){

    ll idx=p[i].second;
  //  cout<<"idx"<<idx<<endl;
    ll wnow=w[idx];
    ll snow=s[idx];
    ll vnow=v[idx];
    rep(j,20005){

      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      //if (j+wnow>10005)continue;
      if (j<=snow)dp[i+1][j+wnow]=max(dp[i+1][j+wnow],dp[i][j]+vnow);
    //  cout<<"j"<<j+wnow<<" "<<dp[i+1][j+wnow]<<endl;
    }
  }
  ll ans=0;
  rep(i,20005){
    ans=max(ans,dp[n][i]);
  }

cout<<ans;
}
