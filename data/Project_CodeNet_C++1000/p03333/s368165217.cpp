#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define MN 100005
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct st{
	int l,r,id;
}a[MN],b[MN];
ll res1,res2;
int n,tot,cur;
bool vis[MN],c;
inline bool cmp(st x,st y){
	return (x.r==y.r)?x.l<y.l:x.r<y.r;
}
inline bool cmp2(st x,st y){
	return (x.l==y.l)?x.r<y.r:x.l<y.l;
}

int main()
{
	n=in();
	for (int i=1;i<=n;++i){
		a[i].l=b[i].l=in();a[i].r=b[i].r=in();
		a[i].id=b[i].id=i;
	}sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp2);
	int hd=1,tl=n;c=tot=cur=0;
	while (tot<n){
		while (vis[a[hd].id]) ++hd;
		while (vis[a[tl].id]) --tl;c^=1;
		if (c){
			res1+=1ll*max(0,b[tl].l-cur);
			if (b[tl].l-cur>0) cur=b[tl].l;
			vis[a[tl].id]=1;--tl;++tot;
		}else{
			res1+=1ll*max(0,cur-a[hd].r);
			if (cur-a[hd].r>0) cur=a[hd].r;
			vis[a[hd].id]=1;++hd;++tot;
		}
	}res1+=1ll*abs(cur);
	hd=1,tl=n;c=1;tot=cur=0;
	memset(vis,0,sizeof(vis));
	while (tot<n){
		while (vis[a[hd].id]) ++hd;
		while (vis[a[tl].id]) --tl;c^=1;
		if (c){
			res2+=1ll*max(0,b[tl].l-cur);
			if (b[tl].l-cur>0) cur=b[tl].l;
			vis[a[tl].id]=1;--tl;++tot;
		}else{
			res2+=1ll*max(0,cur-a[hd].r);
			if (cur-a[hd].r>0) cur=a[hd].r;
			vis[a[hd].id]=1;++hd;++tot;
		}
	}res2+=1ll*abs(cur);
	printf("%lld",max(res1,res2));return 0;
}