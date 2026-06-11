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
  string dp[n+1];
  rep(i,0,n+1) dp[i]="x";
  dp[0]="o";
  rep(i,1,n+1){
    rep(j,0,m){
      if(i>=c[a[j]] && dp[i-c[a[j]]]!="x"){
        if(dp[i].size()<=dp[i-c[a[j]]].size()){
          dp[i]=dp[i-c[a[j]]]+char('0'+a[j]);
        }
        else if(dp[i].size()==dp[i-c[a[j]]].size()+1){
          dp[i]=max(dp[i],dp[i-c[a[j]]]+char('0'+a[j]));
        }
      }
    }
  }
  rep(i,1,dp[n].size()) cout<<dp[n][i];
  cout<<endl;
}