#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e8;

int n;
int a[100005],dp[100005];

int f(int idx)
{
    if(idx==n-1)
        return 0;
    int &ret=dp[idx];
    if(ret!=-1)
        return ret;
    ret=f(idx+1)+abs(a[idx]-a[idx+1]);
    if(idx+2<n)
        ret=min(ret,f(idx+2)+abs(a[idx]-a[idx+2]));
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0)<<endl;
    }
    return 0;
}
