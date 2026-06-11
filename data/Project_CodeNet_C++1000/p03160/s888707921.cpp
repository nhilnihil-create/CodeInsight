#include<iostream>
using namespace std;
int main()
{
    long long n,i;
    cin>>n;
    long long m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    long long dp[n];
    dp[0]=0;
    dp[1]=abs(m[1]-m[0]);
    for(i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(m[i]-m[i-1]),dp[i-2]+abs(m[i]-m[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
