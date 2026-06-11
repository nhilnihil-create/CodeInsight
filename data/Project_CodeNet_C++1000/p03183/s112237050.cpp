#if 1

#include <bits/stdc++.h>
using namespace std;
int n;
long long d[20005];

struct XY
{
    int w,s,v;
}a[1005];

bool cmp(XY x,XY y)
{
    return x.w+x.s < y.w+y.s;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d %d %d", &a[i].w, &a[i].s, &a[i].v);
    }
    sort(a+1,a+n+1,cmp);
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = a[i].s;j >= 0;j--)
        {
            d[j+a[i].w] = max(d[j+a[i].w],d[j]+a[i].v);

        }
        //for(int j = 0;j <= 30;j++) cout << d[j] << " ";
        //cout << '\n';
    }
    for(int i = 0;i <= 20004;i++)
    {
        //cout << d[i] << " ";
        ans = max(ans,d[i]);
    }
    printf("%lld",ans);
}

#endif // 1