#include<bits/stdc++.h>
using namespace std;
long long int dp[200005];
long long int n,k;
vector< int > arr(200005);
long long int mini=1e5;
 int gen(long long int i)
{
    //for(int i=x;i<n;i++)
      //  dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
     // long long int ans;
        if(i>=n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;

        for(int j=1;j<=k;j++)
        {
            if(i+j>=n)
                break;
            ans=min(ans,gen(i+j)+abs(arr[i]-arr[i+j]));
        }



      return dp[i]=ans;
}
int main()
{
   // int n;
    cin>>n>>k;
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
