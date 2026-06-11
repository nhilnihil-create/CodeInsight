#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define mem(x,num) memset(x,num,sizeof x)
#define reg(x) for(int i=last[x];i;i=e[i].next)
using namespace std;
inline ll read(){
    ll f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//******head by yjjr******
#define mid ((l+r)>>1)
const int maxn=2e5+6;
char st[maxn],t[maxn],d[maxn];
int n,Q;
inline int check(int x){
    rep(i,1,Q){
        if(st[x]==t[i])x+=(d[i]=='R')?1:-1;
        if(x>n)return -1;
        if(x<1)return 1;
    }
    return 0;
}
int main(){
    n=read(),Q=read();
    scanf("%s",st+1);
    rep(i,1,Q)cin>>t[i]>>d[i];
    int l=1,r=n,la=0,ra=n+1;
    while(l<=r)if(check(mid)==1)la=mid,l=mid+1;else r=mid-1;
    l=1,r=n;
    while(l<=r)if(check(mid)==-1)ra=mid,r=mid-1;else l=mid+1;
    cout<<ra-la-1<<endl;
    return 0;
}