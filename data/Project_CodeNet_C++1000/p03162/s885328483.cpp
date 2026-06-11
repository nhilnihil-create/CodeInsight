//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int N = 2e7 + 7;
const int mod=1e9+7;
const int INF=1e18+7;
const int dx[] = {-1, 1, 0,  0}; // UDLR
const int dy[] = { 0, 0, -1, 1}; // UDLR
inline int maximum (int a,int b) {int c=a>b?a:b; return c;}
inline int minimum (int a,int b) {int c=a>b?b:a; return c;}

int32_t main (){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);cout.tie(NULL);

       int n,ans=0; cin>>n; tuple<int,int,int> A[n+1]; vector<vector<int>> dp(n+1,vector<int>(3,0));
       for(int i=1;i<=n;i++){
         int a,b,c; cin>>a>>b>>c;
         A[i]={a,b,c};
       }
       dp[1][0]=get<0>(A[1]); dp[1][1]=get<1>(A[1]); dp[1][2]=get<2>(A[1]);
       ans=max({dp[1][0],dp[1][1],dp[1][2]});
       for(int i=2;i<=n;i++){
         for(int j=0;j<3;j++){
          for(int k=0;k<3;k++){
            if(k==j) continue;
            if(j==0) dp[i][j]=maximum(dp[i][j],dp[i-1][k]+get<0>(A[i]));
            if(j==1) dp[i][j]=maximum(dp[i][j],dp[i-1][k]+get<1>(A[i]));
            if(j==2) dp[i][j]=maximum(dp[i][j],dp[i-1][k]+get<2>(A[i]));
          }
           ans=maximum(ans,dp[i][j]);
         }
       }
          cout<<ans;
 return 0;
 }
