#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define float double
const int  LMT =1000000000+5;
#define int long long 
#define lp(i,n) for( i=0;i<n;i++)
const int N=105,M=100005;
int n,m,a[N],i,j,k;
int dp[M];bool vis[N][M];
void solve(){

for(int i=0;i<=k;i++ ){
  if(dp[i])continue;
  for(int j=0;j<n;j++)
    if(a[j]+i<=k)dp[a[j]+i]=1;
}
}
int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
 #endif
 cin>>n>>k;
 memset(dp,0,sizeof(dp));
 lp(i,n){cin>>a[i];dp[a[i]]=1;}
 solve();
 cout<<(dp[k]?"First":"Second")<<endl;
} 