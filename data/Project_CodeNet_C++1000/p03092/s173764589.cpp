#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double db;
const int oo=2139063143;
const int N=5010;
const int P=1000000007;
const db eps=1e-7;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
    if (x< 0) putchar('-'),x=-x;
    if (x>=10) print(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
template <typename T1,typename T2>
void chkmax (T1 &A,T2 B) { A=A>=B?A:B; }
template <typename T1,typename T2>
void chkmin (T1 &A,T2 B) { A=A<=B?A:B; }
int n,A,B;
LL f[N][N];

int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	sc(n),sc(A),sc(B);
	for (int i=1; i<=n; i++)
	{
		int x; sc(x);
		memset (f[i],127,sizeof (LL)*(n+1));
		for (int j=0; j<=n; j++)
		{
			if (x< j) f[i][j]=f[i-1][j]+B;
			else if (x> j) f[i][j]=f[i-1][j]+A;
		}
		for (int j=0; j<=x; j++)
			chkmin (f[i][x],f[i-1][j]);
	}
	LL ans=1e18;
	for (int i=0; i<=n; i++)
		chkmin (ans,f[n][i]);
	pr(ans);

    return 0;
}
