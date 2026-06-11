#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2003, inf = 2e9;
int n, k, q, a[N], b[N];

priority_queue <int, vector <int>, greater <int> > cur, pq;

int get(int x) {
	while (!pq.empty()) pq.pop();
	int len = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < x) continue;
		len++;
		cur.push(a[i]);
		if (i == n || a[i + 1] < x) {
			int can = max(0, len - k + 1);
			while (can--) {
				pq.push(cur.top());
				cur.pop();
			}
			len = 0;
			while (!cur.empty()) cur.pop();
		}
	}
	if ((int)pq.size() < q) return inf;
	int res = 0;
	for (int i = 0; i < q; i++)
		res = max(res, pq.top()), pq.pop();
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	int ans = inf;
	for (int i = 1; i <= n; i++)
		ans = min(ans, get(b[i]) - b[i]);
	cout << ans;
}
