#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  int k,s[20][20]={},p[20],a;
  int ans=0;
  int r[20]={};
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>k;
    for(int j=0;j<k;j++){
      cin>>a;
      s[i][a-1]=1;
    }
  }
  for(int i=0;i<m;i++){
    cin>>p[i];
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
	for(int k=0;k<m;k++){
	  if(s[k][j]==1) r[k]++;
	}
      }
    }
    bool f=true;
    for(int j=0;j<m;j++){
      if(r[j]%2!=p[j]){
	f=false;
      }
      r[j]=0;
    }
    if(f) ans++;
  }
  cout<<ans<<"\n";
}
