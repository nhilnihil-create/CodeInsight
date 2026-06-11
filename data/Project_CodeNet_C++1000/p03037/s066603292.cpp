#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    int ans=0;
    scanf("%d%d",&n,&m);
    k=m;
    int a[100005];
    int u,v;
    memset(a,0,sizeof(a));
    while(m--)
        {
            scanf("%d%d",&u,&v);
            a[u]++;
            a[v+1]--;
        }
        for(int i=1; i<=n; i++)
            a[i]=a[i]+a[i-1];
        for(int i=1; i<=n; i++)
        {
            if(a[i]==k)
                ans++;
        }
    printf("%d",ans);
    return 0;
}
