#include<bits/stdc++.h>
using namespace std;
using LL=long long;
    
struct item{
    int w,s,v;
}a[3005];
    
int n;  LL dp[20005];
    
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v);
    
    sort(a+1,a+n+1,[&](item &x, item &y){return x.s+x.w<y.s+y.w;});

    for(int i=1;i<=n;i++)
        for(int j=min(20000,a[i].w+a[i].s);j>=a[i].w;j--)
            dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
            
    printf("%lld",*max_element(dp+1,dp+20001));
    return 0;
}