#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M=1e9+7;
const int MAX=1<<21;
vector<vector<int>> dp(21,vector<int>(MAX));
int n;
int mat[21][21];
int calc(int i,int left){
    if(i==n){
        return 1;
    }
    if(dp[i][left]!=-1){
        return dp[i][left];
    }
    int ans=0;
    for(int j=0;j<n;j++){
        if(mat[i][j]==1){
            int res=1<<j;
            if(left&res){
                ans+=calc(i+1,left^res)%M;  
                ans%=M;
            }
        }
    }
    return dp[i][left]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
      	dp[i].assign(MAX,-1);
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int sol=calc(0,MAX-1);
    cout<<sol<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}