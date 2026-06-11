#include <bits/stdc++.h>

using namespace std;
int n,k,i,j;
int a[105];
int dp[100005];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=0;i<=k;i++)
    {
        if(!dp[i])
        {
            for(j=1;j<=n;j++)
            {
                if(i+a[j]>k)
                    break;
                dp[i+a[j]]=1;
            }

        }
    }

    if(dp[k])
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}
