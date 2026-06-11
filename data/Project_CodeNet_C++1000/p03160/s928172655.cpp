//g++  7.4.0

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp[n],x=0;
    dp[0]=0;
    for(int i=1;i<n;i++) 
    {
        if(i==1)
        {
            dp[i]=abs(a[i-1]-a[i]);
        }
        else
        {
            dp[i]=min(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+abs(a[i-2]-a[i]));
            //cout<<i<<" "<<min(abs(a[i-1]-a[i]),abs(a[i-2]-a[i])<<endl;
        }
    }
    for(int i=0;i<n;i++)
    {
        //cout<<dp[i]<<endl;
    }
    cout<<dp[n-1];
}