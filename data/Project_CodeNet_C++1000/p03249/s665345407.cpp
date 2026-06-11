#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
using namespace std;
il LL read() {
	LL res = 0,f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -f; ch = getchar();}
	while (isdigit(ch)) {res = res*10+ch-'0'; ch = getchar();} return res*f;
}
namespace qiqi {
	const int N = 1e5+5; int n,siz[N],fa[N]; pair<LL,int> a[N];
	void main() {
		int x; LL d = 0; n = read(); rep(i,1,n) {a[i] = mp(read(),i); siz[i] = 1;} sort(a+1,a+n+1);
		drep(i,n,2) {x = upper_bound(a+1,a+n+1,mp(a[i].fi-n+siz[i]*2,0))-a; if (a[x].fi != a[i].fi-n+siz[i]*2) {puts("-1"); return;} siz[fa[i] = x] += siz[i]; d += siz[i];}
		if (d != a[1].fi) {puts("-1"); return;} rep(i,2,n) printf("%d %d\n",a[i].se,a[fa[i]].se);
	}
}
int main() {
	qiqi::main(); return 0;
}