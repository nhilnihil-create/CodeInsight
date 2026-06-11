#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
const int MAXN = 1e5 + 20;
vector<int> unq;
lint N = 0, n;
int a[MAXN], b[MAXN];
lint tree[MAXN * 2];
inline void clear() {
	rep (i, 0, N) {
		tree[i] = 0;
	}
}
inline void add(int x, int y) {
	x += n + 1;
	while (x <= N) {
		tree[x] += y;
		x += (x & (-x));
	}
}
inline lint query(int x) {
	x += n + 1;
	lint res = 0;
	while (x) {
		res += tree[x];
		x -= (x & (-x));
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	N = n + n + 1;
	rep (i, 1, n) {
		cin >> a[i];
		unq.pb(a[i]);
	}
	sort(all(unq));
	unq.erase(unique(all(unq)), unq.end());
	int l = 0, r = SZ(unq) - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		clear();
		rep (i, 1, n) {
			b[i] = b[i - 1] + (unq[mid] <= a[i] ? 1 : -1);
		}
		lint all = 0;
		rep (i, 1, n) {
			add(b[i - 1], 1);
			all += query(b[i]);
		}
		if (all >= (n * (n + 1) / 2 + 1) / 2) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << unq[l - 1] << endl;
	return 0;
}