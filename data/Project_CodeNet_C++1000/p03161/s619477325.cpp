#include<bits/stdc++.h>
using namespace std;

//int n,k;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //input part has been done
    vector< int> dp(n,INT_MAX);
   // memset(dp,INT_MAX,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=i+k;j++)
        {
            if(j<n)
            {
                dp[j]=min(dp[j],dp[i]+abs(arr[i]-arr[j]));
            }
        }
    }
    cout<<dp[n-1]<<endl;

}
