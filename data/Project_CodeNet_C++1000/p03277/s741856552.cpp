#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
#define pb(x) push_back(x)
#define mkp(x,y) make_pair(x,y)
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int N = 100005;
int n, a[N], p[N], b[N], ans, tr[N<<1];
LL k;
void add(int x, int d) {
	for (int i = x; i <= n * 2 + 1; i += i & -i) tr[i] += d;
}
int ask(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= i & -i) res += tr[i];
	return res;
}
bool check(int mid) {
	memset (tr, 0, sizeof (tr));
	LL res = 0;
	for (int i = 1; i <= n; ++i) p[i] = a[i] >= mid ? 1: -1, p[i] += p[i-1], res += (p[i] >= 0);
	for (int i = 1; i <= n; ++i) p[i] += n + 1;
	for (int i = 1; i <= n; ++i) res += ask(p[i]), add(p[i], 1);
	return res > k / 2 - 1;
}
signed main() {
	n = read(), k = 1ll * n * (n+1) / 2;
	for (int i = 1; i <= n; ++ i) a[i] = b[i] = read();
	sort (b + 1, b + n + 1);
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check (b[mid])) ans = b[mid], l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}