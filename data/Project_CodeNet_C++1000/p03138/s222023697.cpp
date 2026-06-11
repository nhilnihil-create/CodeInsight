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
ll a[N],cnt[2];
ll n,k;

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for(ll j = 42; j >= 0; --j)
    {
        cnt[0] = cnt[1] = 0;
        for(int i = 1; i <= n; ++i)
        {
            cnt[(a[i]>>j)&1ll]++;
        }
        if(cnt[0] > cnt[1] && ans + (1ll << j) <= k)
            ans += (1ll << j);
    }

    ll sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += ans ^ a[i];
    }
    cout<<sum<<endl;
    return 0;
}
