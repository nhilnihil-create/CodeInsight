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
int a[505];
int b[505];

int main()
{
    int n,k;
    cin>>n>>k;
    int ans=-inf;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int l=0; l<=n; l++)
    {
        for(int r=n+1; r>l; r--)
        {
            int cnt=0,sum=0;
            for(int i=1; i<=l; i++)
            {
                b[++cnt]=a[i];
            }
            for(int i=n; i>=r; i--)
            {
                b[++cnt]=a[i];
            }
            if(k<cnt)
                continue;
            sort(b+1,b+1+cnt);
            for(int i=cnt; i>=0; i--)
            {
                if(i<=k-cnt)
                    sum+=max(b[i],0);
                else
                    sum+=b[i];
            }
            ans=max(ans,sum);

        }
    }
    cout<<ans<<endl;
    return 0;
}
