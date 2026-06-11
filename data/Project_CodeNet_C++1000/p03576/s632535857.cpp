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
const int N=1e6+10;
const int mod=1e9+7;
ll a[55],b[55],x[55],y[55];

int main()
{
    int n,k1;
    cin>>n>>k1;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        x[i]=a[i],y[i]=b[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    ll ans=1ll<<62;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                for(int l=k+1; l<n; l++)
                {
                    ll sx = x[i];
                    ll gx = x[j];
                    ll sy = y[k];
                    ll gy = y[l];
                    int cnt=0;
                    for(int m=0;m<n;m++)
                    {
                        if(a[m]>=sx&&a[m]<=gx&&b[m]>=sy&&b[m]<=gy)
                        {
                            cnt++;
                        }
                    }
                    if(cnt>=k1)
                    {
                        ans=min(ans,(gx - sx)*(gy - sy));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
