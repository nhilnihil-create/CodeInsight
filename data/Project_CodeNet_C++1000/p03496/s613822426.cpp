#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  P b[n];
  rep(i,0,n) b[i]=P(a[i],i);
  sort(b,b+n);
  if(b[0].first>=0){
    cout<<n-1<<endl;
    rep(i,0,n-1){
      cout<<i+1<<' '<<i+2<<endl;
      a[i+1]+=a[i];
    }
  }
  else if(b[0].first+b[n-1].first>=0){
    cout<<2*n-2<<endl;
    rep(i,0,n){
      if(i==b[n-1].second) continue;
      cout<<b[n-1].second+1<<' '<<i+1<<endl;
      a[i]+=b[n-1].first;
    }
    rep(i,0,n-1){
      cout<<i+1<<' '<<i+2<<endl;
      a[i+1]+=a[i];
    }
  }
  else{
    cout<<2*n-2<<endl;
    rep(i,0,n){
      if(i==b[0].second) continue;
      cout<<b[0].second+1<<' '<<i+1<<endl;
      a[i]+=b[0].first;
    }
    rep(i,0,n-1){
      cout<<n-i<<' '<<n-1-i<<endl;
      a[n-2-i]+=a[n-1-i];
    }
  }
}