#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e8;

int n;
int a[100005],b[100005],c[100005],dp[100005][2][2][2];

int f(int idx,int sta,int stb,int stc)
{
    if(idx==n)
        return 0;
    int &ret=dp[idx][sta][stb][stc];
    if(ret!=-1)
        return ret;
    if(sta==0)
        ret=f(idx+1,1,0,0)+a[idx];
    if(stb==0)
        ret=max(ret,f(idx+1,0,1,0)+b[idx]);
    if(stc==0)
        ret=max(ret,f(idx+1,0,0,1)+c[idx]);
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
            cin>>a[i]>>b[i]>>c[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0,0,0,0)<<endl;
    }
    return 0;
}
