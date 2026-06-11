#include<bits/stdc++.h>
using namespace std;
long long int dp[200005];
long long int n;
vector<long long int > arr(200005);
long long int mini=1e5;
long long int gen(long long int i)
{
    //for(int i=x;i<n;i++)
      //  dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
      long long int ans;
        if(i>=n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];

        ans=gen(i+1)+abs(arr[i]-arr[i+1]);
        if(i<n-2)
            ans=min(ans,gen(i+2)+abs(arr[i]-arr[i+2]));

      return dp[i]=ans;
}
int main()
{
   // int n;
    cin>>n;
   // vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //input part has been done

    long long int mini=1e5;
    memset(dp,-1,sizeof(dp));
    //initialization
    //dp[0]=0;
    //dp[1]=abs(arr[0]-arr[1]);


    cout<<gen(0);
    //cout<<dp[n-1];
}

