#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,k,n,x;
    cin>>n>>k;
    vector <int> arr(n);
    
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    vector <vector <bool>> dp(n,vector <bool> (k+1));
    for(i=0;i<=k;i++)
    {
        int x=i/arr[0];
        if(x%2)
            dp[0][i]=true;
        else
            dp[0][i]=false;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(j==0)
                dp[i][j]=false;
            bool status=false;
            for(x=0;x<=i;x++)
            {
                if(j-arr[x]>=0&&!dp[i][j-arr[x]])
                {
                    status=true;
                    break;
                }
            }
            dp[i][j]=status;
        }
    }
    if(dp[n-1][k])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}