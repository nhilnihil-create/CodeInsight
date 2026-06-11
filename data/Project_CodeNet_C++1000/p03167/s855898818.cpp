#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define int long long
#define float double
#define LMT 100000000000
#define int long long 
#define lp(i,n) for( i=0;i<n;i++)
const int H=1001,W=1001,mod=1000000000+7;
int dp[H][W]; 


int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
 #endif
  int h,w,i,j;
  cin>>h>>w;char ch;
  memset(dp,0,sizeof(dp));
  int a[h][w],dx[2]={0,-1},dy[2]={-1,0};
  dp[0][0]=1;
  lp(i,h)for(int j=0;j<w;j++){cin>>ch;a[i][j]=ch=='.';}
  for(int i=0;i<h;i++)for(int j=0;j<w;j++){
    if(!a[i][j])continue;
       for(int k=0;k<2;k++)
          {
            int r=i+dx[k],c=j+dy[k];
            if((r<h && r>=0) &&(c>=0 && c<w)){
              dp[i][j]=(dp[i][j]+dp[r][c])%mod;
            }
          }
  }
  cout<<dp[h-1][w-1]<<endl;;
} 