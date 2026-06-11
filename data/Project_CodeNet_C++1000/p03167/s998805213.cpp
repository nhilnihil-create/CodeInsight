#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int

int32_t main()
{
    int N,M;
    cin>>N>>M;
    string A[N];
    
    for(int i=0;i<N;i++)
    {
        string x;
        cin>>x;
        A[i]=x;
    }

    int dp[N][M];
    
    dp[N-1][M-1]=1;
    
    for(int i=N-2;i>=0;i--)
        if(A[i][M-1]=='.')
            dp[i][M-1]=dp[i+1][M-1];
        else
            dp[i][M-1]=0;
            
    for(int i=M-2;i>=0;i--)
        if(A[N-1][i]=='.')
            dp[N-1][i]=dp[N-1][i+1];
        else
            dp[N-1][i]=0;
            
    for(int i=N-2;i>=0;i--)
        for(int j=M-2;j>=0;j--)
            if(A[i][j]=='.')
                dp[i][j]=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
            else
                dp[i][j]=0;
                
    cout<<dp[0][0]%mod;
    return 0;
}