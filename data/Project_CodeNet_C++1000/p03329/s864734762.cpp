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
const int N=1e6+10;
const int mod=1e9+7;
int dp[N];
int main()
{
    memset(dp,inf,sizeof(dp));
    dp[0]=0;
    for(ll i=0; i<=N; i++)
    {
        dp[i+1]=min(dp[i+1],dp[i]+1);
        for(ll j=6; i+j<=N; j*=6)
        {
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
        for(ll j=9; i+j<=N; j*=9)
        {
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    return 0;
}
