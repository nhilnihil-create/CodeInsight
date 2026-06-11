#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n,k;
int a[105];
int dp[105][100005];

in main()
{
    int tc=1;
//    cin>>tc>>st;
    while(tc--)
    {
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=MOD;
                if(j)
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=MOD;
                }
                if(j-a[i]-1>=0){
                    dp[i][j]+=MOD;
                    dp[i][j]-=dp[i-1][j-a[i]-1];
                    dp[i][j]%=MOD;
                }
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}
