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
int a[N],b[N];
ll sum;
int  maxs=-1000;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        maxs=max(maxs,a[i]);
    }
    sort(b,b+n);
    for(int i=n-1;i>=0;i--)
    {
        if(b[i]>=maxs&&m>0)
        {
            sum++;
            m-=b[i];
        }
    }

    if(m<0)
    {
        cout<<sum<<endl;
        return 0;
    }
    sum+=m/maxs;
    if(m%maxs)
    {
        sum++;
    }
    cout<<sum<<endl;
    return 0;
}
