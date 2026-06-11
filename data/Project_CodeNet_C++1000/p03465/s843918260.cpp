/*/-Saya-Javelin-/*/
#include <bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
#define Fo freopen ("in.in", "r", stdin); freopen ("out.out", "w", stdout)
#define Fc fclose (stdin); fclose (stdout)
#define iln inline
#define rgt register
#define Max(a,b) (a)>(b):(a):(b)
#define Min(a,b) (a)<(b):(a):(b)
#define Abs(a) (a)>0?(a):-(a)
#define Swap(a,b) (a)^=(b)^=(a)^=(b)
//#define int long long
#define ll long long
#define ld long double
using namespace std;

const int D=1000000;
char AAA[D];
char *SSR,*UR;
inline char gc(){
	if (SSR==UR) UR=(SSR=AAA)+fread(AAA,1,D,stdin);
	return *SSR++;
}

//#define gc rrr=gc()
#define gc rrr=getchar()
iln void read (int &ur) {
	int ssr=1; char rrr; ur=0;
	while (gc, rrr>'9' || rrr<'0')
	if (rrr=='-') ssr=-1;
	while (rrr>='0' && rrr<='9')
	ur=ur*10+rrr-'0', gc;
	ur=ur*ssr;
	return;
}
#undef gc

iln void write (int ur) {
	if (ur<0) putchar ('-'), ur=-ur;
	if (ur>=10) write (ur/10);
	putchar (ur%10+'0');
	return;
}

iln void wtn (int ur) {
	write (ur);
	putchar ('\n');
	return;
}

iln void wts (int ur) {
	write (ur);
	putchar (' ');
	return;
}

bitset <2002*2002> a;
int n, x[2002], sum=0;

int main () {
	read (n);
	for (rgt int i=1; i<=n; ++i) {
		read (x[i]);
		sum+=x[i];
	}
	a[0]=1;
	for (rgt int i=n; i>=1; --i) {
		a|=a<<x[i];
	}
	for (rgt int i=(sum+1)/2; i<=sum; ++i) {
		if (a.test(i)) {
			wtn (i);
			return 0;
		}
	}
}