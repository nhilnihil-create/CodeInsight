#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];   // dp[i] denotes the longest path starting at node i
char a[1000][1000];
int n,m;
const int N=1e9+7;
void solve(){
   for(int i=0;i<m;++i){
       if(a[0][i]=='#'){
           break;
       }
       dp[0][i]=1;
   }
   for(int i=0;i<n;++i){
       if(a[i][0]=='#'){
           break;
       }
       dp[i][0]=1;
   }

   for(int i=1;i<n;++i){ 
   for(int j=1;j<m;++j){
       if(a[i][j]=='#'){
           dp[i][j]=0;
           continue;
       }
       dp[i][j]=(dp[i-1][j]+dp[i][j-1])%N;     
   }
   }
   return;
}

int32_t main() {
     // int n,m;
       memset(dp,0,sizeof dp);
      cin>>n>>m;
      
      for(int i=0;i<n;++i){ 
      for(int j=0;j<m;++j){
        cin>>a[i][j];
      }
      }
      //int ans=0;
      solve();
    cout<<dp[n-1][m-1];
    return 0;
}
