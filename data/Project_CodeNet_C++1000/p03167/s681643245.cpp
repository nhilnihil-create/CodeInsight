#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;
const unsigned LL M = 1000000007;

int main(){
    LL n,m;cin>>n>>m;
    LL mat[n][m];
    LL dp[n][m]={0};
    
    for (LL i=0;i<n;i++){
        string s; cin>>s;
        for (LL j=0;j<m;j++){
            if (s[j]=='#') mat[i][j]=0;
            else mat[i][j]=1;
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for (LL i=0;i<n;i++){
        for (LL j=0;j<m;j++){
            if (i==0 && j==0) continue;
            if (mat[i][j]==0) continue;
            if (i>0) dp[i][j]+=dp[i-1][j];
            if (j>0) dp[i][j]+=dp[i][j-1];
            dp[i][j]%=M;
            // cout<<mat[i][j]<< " ";
        }
        // cout<<endl;
    }
    cout<<dp[n-1][m-1];
}