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
struct A
{
    int x,y,h;
} a[120];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].h;
    }
    int p=0;
	while(a[p].h==0) p++;
    for(int i=0; i<=101; i++)
    {
        for(int j=0; j<=101; j++)
        {
            int f=0;
            int tem=abs(a[p].x-i)+abs(a[p].y-j)+a[p].h;
            for(int k=0; k<n; k++)
            {
                int ans=tem-abs(a[k].x-i)-abs(a[k].y-j);
                if(ans<0)
                {
                    ans=0;
                }
                if(ans!=a[k].h)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                cout<<i<<' '<<j<<' '<<tem<<endl;
                return 0;
            }
        }
    }

    return 0;
}
