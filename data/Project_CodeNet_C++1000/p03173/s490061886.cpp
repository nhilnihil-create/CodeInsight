#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        ll sum[n][n+1];
        //sum is sum of all elements in [i,j) (although one array is sufficient)
        for(int i=0;i<n;i++)
        {
            sum[i][i]=0;
            for(int j=i+1;j<=n;j++)
                sum[i][j]=sum[i][j-1]+a[j-1];       
        }

        ll dp[n][n+1];
        //dp[i][j] is the minimum cost that will be occurred for array compressing a[i,j) to one element
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                //find answer for a[i...i+len-1] i.e answer for dp[i][i+len]
                if(len==1)
                {
                    dp[i][i+len]=0;
                    continue;
                }
                dp[i][i+len]=LLONG_MAX;
                for(int j=i+1;j<=i+len-1;j++)
                    dp[i][i+len]=min(dp[i][i+len],dp[i][j]+dp[j][i+len]+sum[i][i+len]);
            }
        }

        cout<<dp[0][n]<<endl;
    }
}