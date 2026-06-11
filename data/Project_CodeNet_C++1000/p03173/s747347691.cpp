#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int dp[401][401],n;
int a[401];
int cost(int ac,int bc)
{
    int x=0;
    if(ac) x=a[ac-1];
    return a[bc]-x;
}
int fun(int s,int e)
{
    if(s==e)
        return 0;
    int &ret=dp[s][e];
    if(~ret) return ret;
    ret=1e18;
    for(int i=s;i<e;i++)
        ret=min(ret,cost(s,i)+fun(s,i)+fun(i+1,e)+cost(i+1,e));
    return ret;
}
signed main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i) a[i]+=a[i-1];
    }
    cout<<fun(0,n-1)<<endl;
	return 0;
}

