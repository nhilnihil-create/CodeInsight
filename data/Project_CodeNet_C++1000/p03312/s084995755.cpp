#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
int n;
int a[maxn];
long long sum[maxn];
inline void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
}
inline long long check(int mid)
{
    int L1=1,R1=mid;
    while (L1+1<R1)
    {
        int M=(L1+R1)>>1;
        if (sum[M]<=sum[mid]-sum[M])
            L1=M;
        else
            R1=M;
    }
    int L2=mid+1,R2=n;
    while (L2+1<R2)
    {
        int M=(L2+R2)>>1;
        if (sum[M]-sum[mid]<=sum[n]-sum[M])
            L2=M;
        else
            R2=M;
    }
    long long res=1e18;
    for (int i=L1;i<=R1;i++)
        for (int j=L2;j<=R2;j++)
        {
            long long s1=sum[i],s2=sum[mid]-sum[i],s3=sum[j]-sum[mid],s4=sum[n]-sum[j];
            long long maxx=max(max(s1,s2),max(s3,s4));
            long long minn=min(min(s1,s2),min(s3,s4));
            res=min(res,maxx-minn);
        }
    return res;
}
inline void exec()
{
    long long ans=1e18;
    for (int mid=2;mid<n-1;mid++)
        ans=min(ans,check(mid));
    printf("%lld\n",ans);
}
int main()
{
    init();
    exec();
    return 0;
}
