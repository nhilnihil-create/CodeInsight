#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1001][1001],n,m,mod=1e9+7;
char a[1001][1001];

int call(int i,int j){
    if(i>=n || j>=m || a[i][j]=='#')
        return 0;
    if(i==n-1 && j==m-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=(call(i+1,j)+call(i,j+1))%mod;
    return dp[i][j]=res;
}


int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<call(0,0)<<endl;



return 0;
}
