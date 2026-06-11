#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1003
#define MAX_NW 10000007

struct box{
    int w ,s ,v;
    bool operator<(const box&rhs) const{
        return s+w < rhs.s+rhs.w;
    }
};

int n;
box bs[MAX_N];
long long dp[MAX_NW];

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d",&bs[i].w,&bs[i].s,&bs[i].v);
    sort(bs ,bs+n);

    memset(dp ,-1 ,sizeof dp);
    dp[0] = 0;
    for(int i=0; i<n; i++)
    for(int j=bs[i].s; ~j; j--)
        if(~dp[j])
            dp[j+bs[i].w] = max(dp[j+bs[i].w] ,dp[j]+bs[i].v);

    printf("%lld\n",*max_element(dp ,dp+MAX_NW));
}
