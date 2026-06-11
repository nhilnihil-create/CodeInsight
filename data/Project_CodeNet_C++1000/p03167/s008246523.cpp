#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
#define N 200005
const ll INF = 1000000001;
const ll MOD = 1000000007;
 
int dp[1001][1001];
int ways(int h,int w){
    //int dp[1001][1001]={0};
    if(dp[0][0]==-1){
        return 0;
    }
    
    for(int j=0;j<w;j++){
        if(dp[0][j]==-1){
            break;
        }
        dp[0][j]=1;
    }
    for(int i=0;i<h;i++){
        if(dp[i][0]==-1){
            break;
        }
        dp[i][0]=1;
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(dp[i][j]==-1)
            continue;
            dp[i][j]=0;
            if(dp[i][j-1]!=-1)
            dp[i][j]=dp[i][j-1] % 1000000007;
            if(dp[i-1][j]!=-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000007;
            }
        }
    }
    if(dp[h-1][w-1]==-1){
      return 0;}
    //for(int i=0;i<h;i++){
        //for(int j=0;j<w;j++){
            //cout<<dp[i][j]<<" ";
        //}
       // cout<<endl;
    

    return dp[h-1][w-1];

    
}
int main() {
    int h,w;
    cin>>h>>w;
    memset(dp,0,sizeof dp);
    char grid[1001][1001];
    //char x;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
            //cin>>x;
            if(grid[i][j]=='#'){
                dp[i][j]=-1;
            }
        }
        
    }
   cout<<ways(h,w);

}
