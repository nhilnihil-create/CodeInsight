#include <bits/stdc++.h>
using namespace std;

double dp[3003][3003],H[3003],T[3003];
int main()
{
    int n,i,j,l;
    double sum=0.0;
    scanf("%d",&n);

    for(i=1; i<=n; i++){
        scanf("%lf",&H[i]);
        T[i]=1.0-H[i];
    }

    dp[1][0]=T[1];
    dp[1][1]=H[1];

    for(i=2; i<=n; i++){
        for(j=0; j<=n; j++){          
            if(j==0) dp[i][j]=dp[i-1][j]*T[i];
            else if(j==n) dp[i][j]=dp[i-1][j-1]*H[i];
            else {
                dp[i][j]=dp[i-1][j-1]*H[i] + dp[i-1][j]*T[i];
            }
        }
    }

    l=n/2; l++;
    for(i=l; i<=n; i++){
        sum+=dp[n][i];
    }
    printf("%0.10lf\n",sum);
    return 0;
}