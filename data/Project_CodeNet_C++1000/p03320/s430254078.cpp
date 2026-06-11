//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;

bool operator<(pll l, pll r) {
	return l.fi * r.se < r.fi * l.se;
}

ll sm(ll x) {
	if (x < 10) return x;
	return sm(x/10) + x%10;
}

ll f(ll x) {
	pll opt = mp(x, sm(x));
	ll cur = 1;
	for (int i = 0; cur <= x; i++) {
		x -= ((x / cur) % 10) * cur;
		x += cur * 9;
		if (mp(x, sm(x)) < opt)
			opt = mp(x, sm(x));
		cur *= 10;
	}
	return opt.fi;
}

int main() {
	int k; ni(k);
	if (k < 10) {
		for (int i = 1; i <= k; i++)
			pri(i);
		return 0;
	}
	for (int i = 1; i <= 9; i++)
		pri(i);
	ll cur = 9; k -= 9;
	while (k) {
		cur = f(cur+1);
		prl(cur);
		k--;
	}
	return 0;
}
