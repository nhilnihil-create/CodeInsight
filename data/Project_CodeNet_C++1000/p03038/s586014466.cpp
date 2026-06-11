#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
bool compair(pair<ll,ll>a,pair<ll,ll>b){
  if(a.second!=b.second) return a.second>b.second;
  else return a.first>b.first;
}
int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n);
  rep(i,n) cin>>a[i];
  sort(a.begin(),a.end());
  vector<pair<ll,ll>>b(m);
  rep(i,m) cin>>b[i].first>>b[i].second;
  sort(b.begin(),b.end(),compair);
  vector<ll>c(n);
  int j=0;
  rep(i,n){
    if(b[j].first>0){
      c[i]=b[j].second;
      b[j].first--;
    }
    else{
      if(j==m-1) c[i]=0;
      else{
        j++;
        c[i]=b[j].second;
        b[j].first--;
      }
    }
  }
  ll ans=0;
  rep(i,n) ans+=max(a[i],c[i]);
  cout<<ans<<endl;
}