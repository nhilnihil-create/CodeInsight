#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[100005][3],n;
ll dp[100005][4];
ll vacation(int i,int idx)
{
    if(i>=n)
        return 0;

    if(dp[i][idx]!=-1)
        return dp[i][idx];

    ll temp=0;
    for(int j=1;j<=3;j++)
    {
        if(idx==j)
            continue;

       temp = max(temp,a[i][j]+vacation(i+1,j));
    }
    dp[i][idx]=temp;
    return dp[i][idx];
}


int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<vacation(0,0);


    return 0;
}
