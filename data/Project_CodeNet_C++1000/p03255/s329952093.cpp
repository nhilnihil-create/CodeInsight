#include<bits/stdc++.h>
#define int ll
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
/*inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}*/
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 2e5+233;
int n,x[maxn],s[maxn],X;
signed main(){
	n = rd();X = rd();
	Rep(i,1,n) x[i] = rd(),s[i] = s[i-1] + x[i];
//	ans = n * X;
	__int128 ans = 1e30;
	for(int k=1;k<=n;++k){
		__int128 res = 0;
		__int128 t = 0,w;
		for(int j=n;j>0;j-=k){
			++t;
			if(t==1) w = 5; else w = 2 * t + 1;
//			printf("%lld * %lld\n",s[j]-s[max(0ll,j-k)],w);
			res += (__int128)(s[j] - s[max(0ll,j-k)]) * w;
		}
//		writeln(res);
		ans = min(ans,res+(n+k)*X);
	}
	writeln(ans);
	return 0;
}