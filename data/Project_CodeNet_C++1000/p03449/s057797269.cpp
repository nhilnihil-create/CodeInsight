#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n],b[n];
  rep(i,0,n) cin>>a[i];
  rep(i,0,n) cin>>b[i];
  int c[n+1],d[n+1];
  c[0]=0,d[0]=0;
  rep(i,0,n) c[i+1]=c[i]+a[i];
  rep(i,0,n) d[i+1]=d[i]+b[n-1-i];
  int ans=0;
  rep(i,1,n+1){
    ans=max(ans,c[i]+d[n+1-i]);
  }
  cout<<ans<<endl;
}