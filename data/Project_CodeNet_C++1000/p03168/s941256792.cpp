#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    long long int n,i,j,k,x,y,z;
    cin>>n;
    double p[n+1],dp[n+1][n+1];
    for(i=1;i<=n;i++){
        cin>>p[i];
    }
    for(i=0;i<=n;i++){
        dp[0][i]=0;
    }
    dp[0][0]=1;
    double sum=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            if(j<i)
            dp[i][j]=dp[i-1][j]*(1-p[i]);
            else if(j>=i)
                dp[i][j]=0;
            if(j>0)
                dp[i][j]+=dp[i-1][j-1]*p[i];
        }
    }
    for(j=n/2+1;j<=n;j++){
        sum+=dp[n][j];
    }
    printf("%.9f",sum);
    return 0;
}
