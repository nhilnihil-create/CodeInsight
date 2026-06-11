#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int f[n][10];
  rep(i,0,n){
    rep(j,0,10){
      cin>>f[i][j];
    }
  }
  int p[n][11];
  rep(i,0,n){
    rep(j,0,11){
      cin>>p[i][j];
    }
  }
  int ans=-2e9;
  rep(i,1,1<<10){
    int cur=0;
    rep(j,0,n){
      int cnt=0;
      rep(k,0,10){
        if(f[j][k]==1 && (1 & i>>k)){
          cnt++;
        }
      }
      cur+=p[j][cnt];
    }
    ans=max(ans,cur);
  }
  cout<<ans<<endl;
}