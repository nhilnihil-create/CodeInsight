#include <bits/stdc++.h>
using namespace std;
#define ri register int
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
const int N=2e5+5;
int n,a[N],s[N],b[N],p[N],top,c[N];
inline bool check(ri mid){
	ri i,now;
	while(top) c[p[top--]]=0;
	for(i=2;i<=n;++i){
		if(s[i-1]<s[i]) continue;
		if(mid==1) return false;
		while(top&&p[top]>s[i]) c[p[top--]]=0;
		now=s[i];
		while(top&&p[top]==now&&c[p[top]]==mid-1)
			c[p[top--]]=0,--now;
		if(!now) return false;
		if(p[top]!=now) p[++top]=now;
		++c[now];
	}
	return true;
}
int main(){
	ri i,l,r,mid,lst;
	gi(n);
	for(i=1;i<=n;++i) gi(s[i]);
	for(i=1;i<=n;++i) a[i]=s[i];
	sort(a+1,a+1+n); 
	lst=0;
	for(i=1;i<=n;++i)
		if(a[i]!=a[i-1])
			b[i]=min(a[i],b[lst]+i-lst),
			lst=i;
	for(i=1;i<=n;++i) s[i]=b[lower_bound(a+1,a+1+n,s[i])-a];
	l=1;r=n;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",r+1);
	return 0;
}