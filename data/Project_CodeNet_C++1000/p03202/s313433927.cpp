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
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
const int MAXN = 2e5 + 20;
int a[MAXN], n;
map<int, int> mp;
inline bool check(int mid) {
	mp.clear();
	int tmp = 0;
	if (mid == 1) {
		rep (i, 2, n) {
			if (a[i - 1] >= a[i]) return false;
		}
		return true;
	}
	rep (i, 2, n) if (a[i - 1] >= a[i]) {
		auto it = mp.lower_bound(a[i]);
		mp.erase(it, mp.end());
		++mp[tmp = a[i] - 1];
		while (tmp >= 0 && mp[tmp] >= mid) {
			mp.erase(tmp), ++mp[--tmp];
		}
		if (tmp < 0) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	rep (i, 1, n) {
		cin >> a[i];
	}
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << r + 1 << endl;
	return 0;
}