#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n,m;
  cin >>n>>m;
  vector<long>a(n),b(n),c(n),d(n);
  rep(i,n){
    cin>>a.at(i)>>b.at(i)>>c.at(i);
  }
  long ans=-1001001001001001001;
  long now=0;
  
  rep(i,n){
    d[i]=a[i]+b[i]+c[i];
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  rep(i,m){
    now+=d[i];
  }
  ans=max(ans,now);
  now=0;
  reverse(d.begin(),d.end());
  rep(i,m){
    now-=d[i];
  }
  ans=max(ans,now);
  now=0;
  
  rep(i,n){
    d[i]=a[i]-b[i]+c[i];
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  rep(i,m){
    now+=d[i];
  }
  ans=max(ans,now);
  reverse(d.begin(),d.end());
  now=0;
  rep(i,m){
    now-=d[i];
  }
  ans=max(ans,now);
  now=0;
  
  rep(i,n){
    d[i]=a[i]+b[i]-c[i];
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  rep(i,m){
    now+=d[i];
  }
  ans=max(ans,now);
  now=0;
  reverse(d.begin(),d.end());
  rep(i,m){
    now-=d[i];
  }
  ans=max(ans,now);
  now=0;
  
  rep(i,n){
    d[i]=-a[i]+b[i]+c[i];
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  rep(i,m){
    now+=d[i];
  }
  ans=max(ans,now);
  now=0;
  reverse(d.begin(),d.end());
  rep(i,m){
    now-=d[i];
  }
  ans=max(ans,now);
  
  cout<<ans<<endl;
}