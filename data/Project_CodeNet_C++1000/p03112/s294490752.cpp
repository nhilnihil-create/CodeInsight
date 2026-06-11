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
ll a[N],b[N];
int x,y,q;

int main()
{
    cin>>x>>y>>q;
    for(int i=0; i<x; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<y; i++)
    {
        cin>>b[i];
    }
    ll ans;
    while(q--)
    {
        ll k;
        cin>>k;
        int x1=lower_bound(a,a+x,k)-a;
        int y1=lower_bound(b,b+y,k)-b;
        ans=1e16;
		if(x1<x&&y1<y)
		{
			ans=min(ans,max(a[x1],b[y1])-k);
		}
		if(x1>0&&y1>0)
		{
			ans=min(ans,k-min(a[x1-1],b[y1-1]));
		}
		if(x1>0&&y1<y)
		{
			ans=min(ans,b[y1]-a[x1-1]+min(k-a[x1-1],b[y1]-k));
		}
		if(y1>0&&x1<x)
		{
			ans=min(ans,a[x1]-b[y1-1]+min(k-b[y1-1],a[x1]-k));
		}
		printf("%lld\n",ans);
    }
    return 0;
}
