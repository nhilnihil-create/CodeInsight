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
map<ll,ll> mp;
int main()
{
    ll sum=0;
    ll ans=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans+=x;
        if(ans==0)
        {
            sum+=mp[ans]+1;
        }
        else
        {
            sum+=mp[ans];
        }
        mp[ans]++;
    }
    cout<<sum<<endl;
    return 0;
}
