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
const int N=2e5+10;
const int mod=1e9+7;
ll dp1[N];
ll dp2[N];
ll a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    a[0]=a[1],a[n+1]=a[n];
    for(int i=1; i<=n; i++)
    {
        dp1[i]=__gcd(a[i],dp1[i-1]);
    }
    for(int i=n; i>=1; i--)
    {
        dp2[i]=__gcd(a[i],dp2[i+1]);
    }

    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
            ans=max(ans,dp2[i+1]);
        }
        else if(i==n)
        {
            ans=max(ans,dp1[i-1]);
        }
        else
        {
            ll tem=__gcd(dp2[i+1],dp1[i-1]);
            ans=max(ans,tem);
        }
    }
    cout<<ans<<endl;
    return 0;
}
