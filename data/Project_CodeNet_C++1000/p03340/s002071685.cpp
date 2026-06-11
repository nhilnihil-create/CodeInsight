
#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<algorithm>
#include<deque>
#include<string.h>
#define ll long long
//#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ll num[200005];
        for(int i=0; i<n; i++)
            scanf("%lld",&num[i]);
        int r=0;
        ll sum0 = 0,sum1 = 0,ans = 0;
        for(int l=0; l<n; l++)
        {
            //r=l;
            while((sum0^num[r])==(sum1+num[r])&&r<n)
            {
                sum0 ^= num[r];
                sum1 += num[r++];
            }
            ans+=(r-l);
            sum0 ^= num[l];
            sum1 -= num[l];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
