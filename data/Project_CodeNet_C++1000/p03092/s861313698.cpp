#include <bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll; 
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
int p[N],f[N],a[N][N];
ll dp[N];
inline int query(ri x1,ri x2,ri y1,ri y2){
	return x1<=x2&&y1<=y2?a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]:0;
}
int main(){
	ri n,A,B,i,j;
	gi(n);gi(A);gi(B);
	for(i=1;i<=n;++i) gi(p[i]),a[i][p[i]]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	p[n+1]=n+1;
	for(i=1;i<=n+1;++i){
		dp[i]=inf;
		for(j=i-1;j>=0;--j)
			if(p[j]<p[i])
				dp[i]=min(dp[i],dp[j]+(ll)A*query(j+1,i-1,p[i]+1,n)+(ll)B*query(j+1,i-1,1,p[i]-1));
	}
	printf("%lld\n",dp[n+1]);
	return 0;
}