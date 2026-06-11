#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
int f[N],r[N][2];
ll ans[N],b[N];
int finds(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    else
    {
        return f[x]=finds(f[x]);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>r[i][0]>>r[i][1];
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        b[i]=1;
    }
    ll sum=1ll*n*(n-1)/2;
    for(int i=m-1;i>=0;i--)
	{
		ans[i]=sum;
		int x=r[i][0];
		int y=r[i][1];
		finds(x);
		finds(y);
		if(f[x]==f[y])
		{
			continue;
		}
		sum-=((b[f[x]]+b[f[y]])*(b[f[x]]+b[f[y]]-1)/2-b[f[x]]*(b[f[x]]-1)/2-b[f[y]]*(b[f[y]]-1)/2);
		b[f[y]]+=b[f[x]];
		f[f[x]]=f[y];
	}
	for(int i=0;i<m;i++)
	{
		printf("%lld\n",ans[i]);
	}
    return 0;
}
