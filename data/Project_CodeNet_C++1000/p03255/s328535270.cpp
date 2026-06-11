#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int N=1e6;
int n;
LL x,ans=INF,a[N+10],b[N+10];
LL Sqr(LL x) {
    return x*x;
}
int main() {
    scanf("%d%lld",&n,&x);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    LL nowsum=0;
    for (int i=1;i<=n;i++) {
        LL sum=0;
        nowsum=min(INF,nowsum+(a[n-i+1]-a[n-i])*i*5);
        for (int j=n-i;j>=1;j-=i) {
            int l=max(j-i+1,1);
            int sz=j-l+1;
            LL nowx=b[j]-b[l-1]-a[l-1]*sz;
            LL k=Sqr((n-j)/i+2)-Sqr((n-j)/i+1);
            LL Base=Sqr((n-j)/i+1)*i;
            double value=1.0*nowx*k+1.0*Base*(a[j]-a[l-1]);
            if (value>INF) {
                sum=INF;
                break;
            }
            sum=min(INF,sum+nowx*k+Base*(a[j]-a[l-1]));
        }
        sum+=x*(n+i)+nowsum+a[n-i]*i;
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}
