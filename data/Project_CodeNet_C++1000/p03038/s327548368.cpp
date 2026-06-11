

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  vector<P> v(m);
  rep(i,m){
    ll b1,c1;
    cin>>b1>>c1;
    v[i].first=c1;
    v[i].second=b1;
  }
  sort(a.begin(),a.end());
  sort(v.rbegin(),v.rend());

  vector<ll> s(n);
  ll now=0;
  rep(i,m){
    if (now>=n)break;
    for(ll j=now;j<now+v[i].second;j++){
      if (j>=n)break;
      s[j]=v[i].first;
    }
    now+=+v[i].second;
  }
  ll ans=0;
  rep(i,n){
    if (s[i]>a[i])ans+=s[i];
    else ans+=a[i];
  }
  cout<<ans;
}
