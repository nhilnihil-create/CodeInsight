#include <bits/stdc++.h>
using namespace std;



int main() {
    int m,n;
    cin>>m>>n;
    vector<string> g;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        g.push_back(s);
    }
    vector<vector<long long int>> dp(m,vector<long long int>(n,0));
    for(int i=0;i<n;i++){
        if(g[0][i]=='.')
            dp[0][i]=1;
        else
            break;
    }
    
    for(int i=0;i<m;i++){
        if(g[i][0]=='.')
            dp[i][0]=1;
        else
            break;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(g[i][j]=='.')
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    cout<<dp[m-1][n-1];
    return 0;
}