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
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll f[110][110];
ll p[110][110];//(i,j)表示第I个天开J个店的收入
ll d[110];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>f[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            cin>>p[i][j];
        }
    }
    ll  maxs=-inf;
    for(int s=1;s<(1<<10);s++)
    {
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            for(int j=1;j<=10;j++)
            {
                if(f[i][j]<<(j-1)&s)
                {
                    d[i]++;
                }
            }
        }
        ll ans=0;
        for(int i = 1; i <= n; i++)
        {
            ans+=p[i][d[i]];
        }
        maxs=max(maxs,ans);
    }
    cout<<maxs<<endl;
    return 0;
}
