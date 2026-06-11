#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int c[10]={0,2,5,5,4,5,6,3,7,6};

int main(){
  int n,m;
  cin>>n>>m;
  int a[m];
  rep(i,0,m) cin>>a[i];
  sort(a,a+m);
  reverse(a,a+m);
  int dp[n+1];
  rep(i,0,n+1) dp[i]=-1;
  dp[0]=0;
  rep(i,1,n+1){
    rep(j,0,m){
      if(i>=c[a[j]] && dp[i-c[a[j]]]!=-1){
        dp[i]=max(dp[i],dp[i-c[a[j]]]+1);
      }
    }
  }
  //rep(i,0,n+1) cout<<dp[i];
  int cur=n;
  while(cur>0){
    rep(i,0,m){
      if(cur-c[a[i]]>=0 && dp[cur]==dp[cur-c[a[i]]]+1){
        cur-=c[a[i]];
        cout<<a[i];
        break;
      }
    }
  }
  cout<<endl;
}