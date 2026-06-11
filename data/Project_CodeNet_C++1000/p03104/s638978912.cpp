#include <bits/stdc++.h>

#define rep(i, l, r) for(int i = l, i##end = r; i <= i##end; ++i)
#define per(i, l, r) for(int i = l, i##end = r; i >= i##end; --i)
#define repo(i, l, r) for(int i = l, i##end = r; i < i##end; ++i)
#define pero(i, l, r) for(int i = l, i##end = r; i > i##end; --i)
#define debug(x) cerr << "debug(" << #x << ')' << ": " << x << " " << endl
typedef long long ll;
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MAXN = 1 * 1e5 + 5;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
inline ll read() {
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
//int cmpfunc (const void * a, const void * b){return ( *(int*)a - *(int*)b );}
//rise; qsort (a, n, sizeof(int), cmpfunc);

/*struct cmp{bool operator( ) (int x, int y) const {return a[x] + b[x] > a[y] + b[y];}};*/

ll a, b;
ll GEt_ans(ll n) {
	ll t = n & 3;
	if (t & 1) return t / 2 ^ 1;
	return t / 2 ^ n;
}
void solve() {
	cin >> a >> b;
	ll x = GEt_ans(a-1), y = GEt_ans(b);
	ll sum = y ^ x;
	cout << sum << endl;
}

int main() {
#ifdef ACM_LOCAL
	freopen("in.txt", "r", stdin);
#endif
//	int T; cin >> T;
//	while(T--)
	solve();
	return 0;
}