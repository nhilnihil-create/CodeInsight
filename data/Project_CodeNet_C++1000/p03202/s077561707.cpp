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
const int MAXN = 2e5 + 5;
const double eps = 1e-9;
int a[MAXN], n;

bool ok(int cnt) {
	stack<pii> st;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i-1]) continue;
		while (!st.empty() && st.top().fi > a[i])
			st.pop();
		int idx = 0;
		while (!st.empty() && st.top().fi + idx == a[i] && st.top().se == cnt) {
			st.pop();
			idx++;
		}
		if (idx == a[i] || cnt == 1) {
			return false;
		} else {
			int col = 2;
			if (!st.empty() && st.top().fi + idx == a[i]) {
				col = st.top().se + 1;
				st.pop();
			}
			st.push(mp(a[i]-idx,col));
		}
	}
	return true;
}

int main() {
	ni(n); nai(a, n);
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mi = (lo+hi) / 2;
		if (ok(mi))
			hi = mi - 1;
		else
			lo = mi + 1;
	}
	pri(lo);
	return 0;
}
