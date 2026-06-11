#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll; //记得开 long long
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
    reg char ch=getchar();
    reg int res=0;
    while(ch<'0'||'9'<ch)ch=getchar();
    while('0'<=ch&&ch<='9')res=10*res+ch-'0',ch=getchar();
    return res;
}

int n;
vector<ll> a,b,ta,tb;

int main(void){
    n=read();
    for(reg int i=1;i<=n;++i){ //读入 a
        static ll x;
        x=read();
        a.push_back(x);
    }
    for(reg int i=1;i<=n;++i){ //读入 b
        static ll x;
        x=read();
        b.push_back(x);
    }
    reg ll ans=0;
    for(reg int i=29;i>=0;--i){ //枚举每一位
        reg ll T=(1<<i),mod=(T<<1);
        for(reg int j=0;j<n;++j){
            a[j]&=mod-1;
            b[j]&=mod-1; //可以用 & 运算代替这里的取模（对 2 的幂次取模）
        }
        sort(b.begin(),b.end()); //排序
        reg int cnt=0;
        for(reg int j=0;j<n;++j){ //求区间长度
            cnt+=lower_bound(b.begin(),b.end(),T*2-a[j])-lower_bound(b.begin(),b.end(),T-a[j]);
            cnt+=lower_bound(b.begin(),b.end(),T*4-a[j])-lower_bound(b.begin(),b.end(),T*3-a[j]);
        }
        if(cnt&1) //最后求异或的贡献
            ans|=T;
    }
    printf("%lld\n",ans); //输出答案
    return 0;
}
