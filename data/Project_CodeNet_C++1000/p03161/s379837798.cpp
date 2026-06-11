#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e8;

int n,k;
int a[100005],dp[100005];

int f(int idx)
{
    if(idx==n-1)
        return 0;
    int &ret=dp[idx];
    if(ret!=-1)
        return ret;
    ret=f(idx+1)+abs(a[idx]-a[idx+1]);
    for(int i=2; i<=k; i++)
    {
        if(idx+i<n)
            ret=min(ret,f(idx+i)+abs(a[idx]-a[idx+i]));
    }
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0)<<endl;
    }
    return 0;
}
