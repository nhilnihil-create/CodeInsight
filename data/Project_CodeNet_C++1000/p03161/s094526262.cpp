#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long int ar[n+5];
    for(int i=0;i<n;i++)scanf("%lld",&ar[i]);

    long long int dp[n+2];
    dp[0]=0;

    dp[1]=abs(ar[1]-ar[0]);
    for(int i=2;i<n;i++)
    {
        int second=i-k;
        if(second<0)second=0;
        dp[i]=dp[second]+abs(ar[second]-ar[i]);
        for(int j=second+1;j<i;j++)
        {
            int dif=abs(ar[j]-ar[i]);
            dp[i]=min(dp[j]+dif,dp[i]);
        }
    }

//    cout<<"Dp array is : "<<endl;
//    for(int i=0;i<n;i++)cout<<dp[i]<<" ";
//    cout<<endl;

    printf("%lld\n",dp[n-1]);

    return 0;

}
