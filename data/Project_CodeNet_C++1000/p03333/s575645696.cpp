#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define reg register
typedef long long ll;
inline int read(){
    reg int x=0,f=1;reg char ch=getchar();
    for(;!isdigit(ch);f=ch=='-'?-1:1,ch=getchar());
    for(;isdigit(ch);x=x*10+(ch^48),ch=getchar());
    return x*f;
}
const int MN=1e5+5;
struct seg{int l,r,id;}a[MN],b[MN];
inline bool cmp1(seg a,seg b){return a.r==b.r?a.l<b.l:a.r<b.r;}
inline bool cmp2(seg a,seg b){return a.l==b.l?a.r<b.r:a.l<b.l;}
int n;
bool vis[MN];
ll ans1,ans2;
int main(){
	n=read();
	for(reg int i=1;i<=n;i++)a[i].l=read(),a[i].r=read(),a[i].id=i,b[i]=a[i];
	std::sort(a+1,a+1+n,cmp1);std::sort(b+1,b+1+n,cmp2);
	reg int lt=1,rt=n,f=0,pos=0;
	while(lt<=rt){
		while(vis[a[lt].id])lt++;while(vis[a[rt].id])rt--;
		if(f){
			if(a[lt].r<pos)ans1+=pos-a[lt].r,pos=a[lt].r;vis[a[lt++].id]=1;
		}
		else{
			if(b[rt].l>pos)ans1+=b[rt].l-pos,pos=b[rt].l;vis[a[rt--].id]=1;
		}
		f^=1;
	}
	ans1+=std::abs(pos);memset(vis,pos=0,sizeof(vis));f=lt=1;rt=n;
	while(lt<=rt){
		while(vis[a[lt].id])lt++;while(vis[a[rt].id])rt--;
		if(f){
			if(a[lt].r<pos)ans2+=pos-a[lt].r,pos=a[lt].r;vis[a[lt++].id]=1;
		}
		else{
			if(b[rt].l>pos)ans2+=b[rt].l-pos,pos=b[rt].l;vis[a[rt--].id]=1;
		}
		f^=1;
	}
	printf("%lld\n",std::max(ans1,ans2+std::abs(pos)));
    return 0;
}