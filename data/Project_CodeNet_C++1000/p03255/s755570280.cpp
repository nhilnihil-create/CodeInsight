//2018.10.19 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f3f3f3f
#define eps 1e-15
inline LL read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=2e5+10;
namespace MAIN{
    LL n,x;
    LL a[N],sum[N];
    LL ans=inf;
    inline void MAIN(){
        n=read(),x=read();
        for(res i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
        for(res k=1;k<=n;k++){
            res tot=0;
            for(res i=n;i>=1;i-=k){
                tot+=(sum[i]-sum[_max(0,i-k)])*(i==n?5:2*((n-i)/k)+3);
                if(tot+(k+n)*x>=ans)break;
            }
            ans=_min(ans,tot+(k+n)*x);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}