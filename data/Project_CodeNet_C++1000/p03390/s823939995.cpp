#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
int Q;
LL a,b;
LL LLsqrt(LL x){
    LL L=0,R=1e9,mid,ans=-1;
    while (L<=R){
        mid=(L+R)>>1;
        if (mid*mid<=x)
            L=mid+1,ans=mid;
        else
            R=mid-1;
    }
    return ans;
}
int main(){
    scanf("%d",&Q);
    while (Q--){
        scanf("%lld%lld",&a,&b);
        if (a>b)
            swap(a,b);
        LL c=a*b-1;
        LL d=LLsqrt(c);
        LL ans=d+d;
        if (a!=b)
            ans--;
        if (d!=0)
            if (d==c/d)
                ans--;
        printf("%lld\n",max(ans,0LL));
    }
    return 0;
}