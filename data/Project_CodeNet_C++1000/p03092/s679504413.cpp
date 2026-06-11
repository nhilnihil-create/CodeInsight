#include <bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll; 
#define rll register ll
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x << 1) + (x << 3) + (c & 15); x *= f;
	}
	// input a letter
	template <class I>
	inline void get (I &x) {
		for (c = gc(); c < 'A' || c > 'Z'; c = gc()) ;
		x = c;
	}
	// input a string
	inline void read (char *s){
		for(c = gc(); c < 'A' || c > 'Z'; c = gc()) ;
		for(; c >= 'A' && c <= 'Z'; c = gc()) *++s = c;
		*++s = '\0';
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: get;
using io :: read;
using io :: putc;
using io :: print;
const int N=5005;
const ll inf=1e18;
struct segtree{
	ll mn[N<<2],tag[N<<2];
	#define lc x<<1
	#define rc x<<1|1 
	inline void build(ri x,ri l,ri r){
		mn[x]=inf;
		if(l==r)
			return;
		ri mid=l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	inline void up(ri x){
		mn[x]=min(mn[lc],mn[rc])+tag[x];
	}
	inline void upd(ri x,ri l,ri r,ri p,rll v){
		v-=tag[x];
		if(l==r){
			mn[x]=v+tag[x];
			return;
		}
		ri mid=l+r>>1;
		p<=mid?upd(lc,l,mid,p,v):upd(rc,mid+1,r,p,v);
		up(x);
	}
	inline void modify(ri x,ri l,ri r,ri ql,ri qr,rll v){
		if(ql<=l&&r<=qr){
			mn[x]+=v;
			tag[x]+=v; 
			return;
		}
		ri mid=l+r>>1;
		if(ql<=mid) modify(lc,l,mid,ql,qr,v);
		if(qr> mid) modify(rc,mid+1,r,ql,qr,v);
		up(x);
	}
	inline ll query(ri x,ri l,ri r,ri ql,ri qr){
		if(ql<=l&&r<=qr)
			return mn[x];
		ri mid=l+r>>1;
		rll v=inf;
		if(ql<=mid) v=		query(lc,l,mid,ql,qr);
		if(qr> mid) v=min(v,query(rc,mid+1,r,ql,qr));
		v+=tag[x];
		return v;
	}
}seg;
int p[N];
ll dp[N];
int main(){
	ri n,A,B,C,i,j;
	gi(n);gi(A);gi(B);
	C=B-A;
	for(i=1;i<=n;++i) gi(p[i]);
	p[n+1]=n+1;
	seg.build(1,0,n+1);
	seg.upd(1,0,n+1,0,0);
	for(i=1;i<=n+1;++i)
		dp[i]=seg.query(1,0,n,0,p[i]-1)+(ll)A*(i-1),
		seg.upd(1,0,n+1,p[i],dp[i]-(ll)A*i),
		seg.modify(1,0,n+1,p[i]+1,n+1,C);
	printf("%lld\n",dp[n+1]);
	return 0;
}