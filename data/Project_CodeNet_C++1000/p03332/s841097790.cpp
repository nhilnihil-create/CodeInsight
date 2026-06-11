#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

template <typename QvQ> inline QvQ Min(QvQ a,QvQ b){if(a<b) return a;return b;}
template <typename QvQ> inline QvQ Max(QvQ a,QvQ b){if(a>b) return a;return b;}

#define inf 2147483647
#define dinf 0x3f3f3f3f
#define llinf 0x7f7f7f7f7f7f7f7f

#define ll long long
#define rei register int
#define inv inline void
#define ull unsigned long long
#define il inline

#define bl putchar(' ')
#define ed putchar('\n')
#define test cout<<"this:" 

#define read2(a,b) read(a),read(b)
#define write2(a,b) write(a),bl,write(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define write3(a,b,c) write(a),bl,write(b),bl,write(c)

template <typename QvQ>inv read(QvQ &x){
	x=0;int f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x=x*f;
}
template <typename QvQ>inv write(QvQ x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+48);
}
using namespace std;
#define int long long
const int maxn=3e5+5;
const int mod=998244353;
int n,a,b,k;
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod; b>>=1;
	}
	return ret;
}
int jc[maxn],iv[maxn];
void init(){
	jc[0]=1; for(rei i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
	iv[n]=qpow(jc[n],mod-2); iv[0]=1;
	for(rei i=n-1;i>=1;--i) iv[i]=iv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	return jc[n]*iv[n-m]%mod*iv[m]%mod;
}
signed main(){
	read(n),read3(a,b,k);
	init(); int ans=0;
	for(rei i=0;i<=n&&i<=k/a;++i){
		int rp=i*a,bp=k-rp;
		if(bp%b) continue;
		int bc=bp/b;
		if(bc>n) continue;
		ans=(ans+C(n,i)*C(n,bc)%mod)%mod;
	}
	write(ans),ed;
	return 0;
}