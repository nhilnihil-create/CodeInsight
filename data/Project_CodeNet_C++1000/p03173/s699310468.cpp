#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int n;
int a[401];
int dp[401][401];
int csum[401];
int fun(int s,int e)
{
    if(s>=e) return 0;
    int &ret=dp[s][e];
    if(~ret)
        return ret;
    ret=1e18;
    for(int i=s;i<e;i++)
    {
        ret=min(ret,fun(s,i)+csum[i]-(!s?0:csum[s-1])+fun(i+1,e)+csum[e]-csum[i]);
    }
    return ret;
}
signed main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(!i) csum[i]=a[i];
        else csum[i]=csum[i-1]+a[i];
    }
    cout<<fun(0,n-1)<<endl;
	return 0;
}

