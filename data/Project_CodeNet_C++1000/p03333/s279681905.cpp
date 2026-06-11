#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=1e5+10;
int id1[maxn],id2[maxn],p[maxn];
struct point{
	int l,r;
}a[maxn];
bool cmpr(const int &A,const int &B){
	return a[A].r<a[B].r;
}
bool cmpl(const int &A,const int &B){
	return a[A].l>a[B].l;
}
int main(){
	int n=read();
	REP(i,1,n) a[i].l=read(),a[i].r=read(),id1[i]=id2[i]=i;
	sort(id1+1,id1+n+1,cmpr);
	sort(id2+1,id2+n+1,cmpl);
	ll tmp=0,ans=0;
	int flag=0,i=1,j=1,lst=0;
	REP(k,1,n){
		while(i<=n && p[id1[i]]) ++i;
		while(j<=n && p[id2[j]]) ++j;
		if(flag){
			if(a[id1[i]].r<lst) p[id1[i]]=1,tmp+=lst-a[id1[i]].r,lst=a[id1[i]].r;
		}
		else{
			if(a[id2[j]].l>lst) p[id2[j]]=1,tmp+=a[id2[j]].l-lst,lst=a[id2[j]].l;
		}
		flag^=1;
	}
	tmp+=abs(lst);ans=max(ans,tmp);
	tmp=0;
	flag=1,i=1,j=1,lst=0;
	memset(p,0,sizeof(p));
	REP(k,1,n){
		while(i<=n && p[id1[i]]) ++i;
		while(j<=n && p[id2[j]]) ++j;
		if(flag){
			if(a[id1[i]].r<lst) p[id1[i]]=1,tmp+=lst-a[id1[i]].r,lst=a[id1[i]].r;
		}
		else{
			if(a[id2[j]].l>lst) p[id2[j]]=1,tmp+=a[id2[j]].l-lst,lst=a[id2[j]].l;
		}
		flag^=1;
	}
	tmp+=abs(lst);ans=max(ans,tmp);
	printf("%lld\n",ans);
	return 0;
}