#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
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
const int maxn=2e5+10;
int n,a[maxn],idx[maxn],idx_cnt;
struct szsz{
	int c[maxn];
	inline int lowbit(int x){
		return x&(-x);
	}
	int sum(int x){
		int res=0;
		while(x){
			res+=c[x];
			x-=lowbit(x);
		}
		return res;
	}
	void add(int x){
		while(x<=maxn-10){
			c[x]++;
			x+=lowbit(x);
		}
	}
	void clear(){
		REP(i,1,maxn-10) c[i]=0;
	}
}bit;
bool check(int x){
	ll res=0;
	int cur=1e5;
	bit.clear();
	bit.add(cur);
	REP(i,1,n){
		if(a[i]>=x) ++cur;else --cur;
		res+=bit.sum(cur);
		bit.add(cur);
	}
	return 2*res>=(ll)n*(n+1)/2;
}
int main(){
	n=read();
	REP(i,1,n) a[i]=read(),idx[++idx_cnt]=a[i];
	sort(idx+1,idx+idx_cnt+1);
	idx_cnt=unique(idx+1,idx+idx_cnt+1)-idx-1;
	REP(i,1,n) a[i]=lower_bound(idx+1,idx+idx_cnt+1,a[i])-idx;
	int L=1,R=idx_cnt;
	while(L<=R){
		int Mid=(L+R)>>1;
		if(check(Mid)) L=Mid+1;
		else R=Mid-1;
	}
	printf("%d\n",idx[L-1]);
	return 0;
}