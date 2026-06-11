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
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
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
bitset <2000010> b;
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	int n,sum=0; sc(n);
	b[0]=1;
	while (n--)
	{
		int x; sc(x);
		sum+=x;
		b|=b<<x;
	}
	for (int i=(sum+1)/2; i<=sum; i++)
		if (b[i]) return pr(i),0;

	return 0;
}
