#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define float double
const int  LMT =1000000000+5;
#define int long long 
#define lp(i,n) for( i=0;i<n;i++)
const int N=3005,M=3005;
int n,m,w[N],v[N],i,j;string a,b;
int dp[N][M];bool vis[N][M];
void solve(int n,int m){
for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    }

}
}
int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
 #endif
 cin>>a>>b;
 a='@'+a;b='@'+b; memset(dp,0,sizeof(dp));
 solve(n=a.length(),m=b.length());
  // cout<<dp[n-1][m-1]<<endl;
  i=n-1;j=m-1; string ans="";

/*for(int i=0;i<n;i++){cout<<endl;
    for(int j=0;j<m;j++)
   cout<<dp[i][j]<<" ";

    }*/

  while(i>0 && j>0){
   // cout<<ans<<endl;
    //cout<<i<<" "<<j<<" ";
    int curr=dp[i][j],ca=dp[i-1][j-1],cl=dp[i][j-1],cu=dp[i-1][j];
    int mx=max(max(cl,cu),ca);
    //cout<<"mx="<<mx<<endl;
    if(mx==ca){

      if(mx < dp[i][j])ans+=a[i];
      i--;j--;continue;
    }
    if(mx==cl){
      if(mx < dp[i][j])ans+=a[i];
      j--;continue;

    }
    else{
      if(mx<dp[i][j])ans+=a[i];
      i--;
    }
  }

 reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
 
} 