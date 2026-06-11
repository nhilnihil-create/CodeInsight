#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int maxn=1e5+10;
int a[maxn];
int n;
int c[maxn*15];
int pre[maxn*15];
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    for(int i=x;i<=2*maxn;i+=lowbit(i))c[i]++;
}
LL query(int x)
{
    LL res=0;
    for(int i=x;i>0;i-=lowbit(i))res+=c[i];
    return res;
}

bool check(int x)
{
    memset(c,0,sizeof(c));
    pre[0]=0;
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(a[i]>=x?1:-1);
    LL res=0;
    for(int i=0;i<=n;i++){
        res+=query(pre[i]+maxn);
        add(pre[i]+maxn);
    }
    return res>=1LL*n*(n+1)/4;
}

int main()
{
    n=read();
    int L=0,R=0,ans=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        R=max(R,a[i]);
    }
    while(L<=R){
        int mid=(L+R)>>1;
        if(check(mid)){
            L=mid+1;ans=mid;
        }
        else{
            R=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}