// Date: 2020-01-27

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

struct edge {
	int u, v, w;
};
vector<edge> E;
void add(int u, int v, int w) {
	E.pb({u, v, w});
}
int main() {
	int L, LL;
	scanf("%d", &L);
	LL = L;
	VI vec;
	while(L) {
		vec.pb(L % 2);
		L /= 2;
	}
	L = LL;
	int n = vec.size();
	for(int i = 1; i < n; i++) {
		add(i, i+1, 0);
		add(i, i+1, 1 << (i-1));
	}
	int y = L-(1<<(n-1)), cur = (1 << (n-1));
	while(y) {
		int x = 0;
		while((1 << (x+1)) < y) x++;
		add(x+1, n, cur);
		y -= (1 << x);
		cur += (1 << x);
	}
	printf("%d %d\n", n, E.size());
	for(auto e : E) {
		printf("%d %d %d\n", e.u, e.v, e.w);
	}

	return 0;
}