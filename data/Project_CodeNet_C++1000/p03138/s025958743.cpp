#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  ll k;
  cin>>n>>k;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  
  bool b[40];
  rep(i,0,40){
    if(k%2) b[i]=true;
    else b[i]=false;
    k/=2;
  }
  
  int c[40];
  rep(i,0,40) c[i]=0;
  rep(i,0,n){
    rep(j,0,40){
      if(a[i]%2) c[j]++;
      a[i]/=2;
    }
  }
  
  ll d[40];
  d[0]=1;
  rep(i,0,39) d[i+1]=d[i]*2;
  
  bool p=false;
  ll ans=0;
  rep(i,0,40){
    if(p){
      ans+=d[39-i]*max(c[39-i],n-c[39-i]);
    }
    else{
      if(b[39-i]){
        if(c[39-i]<=n/2){
          ans+=d[39-i]*(n-c[39-i]);
        }
        else{
          ans+=d[39-i]*c[39-i];
          p=true;
        }
      }
      else{
        ans+=d[39-i]*c[39-i];
      }
    }
  }
  cout<<ans<<endl;
}