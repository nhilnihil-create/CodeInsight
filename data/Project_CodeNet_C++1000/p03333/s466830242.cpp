#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

bool vis[N];
int X[N], Y[N];
ll get(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i;
	ll ans = 0;
	do {
		int point = 0;
		ll temp = 0;
		for (int i = 0; i < v.size(); i++) {
			int l = X[v[i]];
			int r = Y[v[i]];
			if (point >= l && point <= r) continue;
			if (point < l) {
				temp += abs(point - l);
				point = l;
			} else if (point > r) {
				temp += abs(point - r);
				point = r;
			}
		}
		ans = max(ans, temp + abs(point));
	} while (next_permutation(v.begin(), v.end()));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	srand(time(0));
//	int t = 50;
	int n;
	cin >> n;
	set<pair<int, int> > l, r;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		X[i] = a, Y[i] = b;
		l.insert(make_pair(a, i));
		r.insert(make_pair(b, i));
	}
	int point = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		while (l.size() && vis[l.rbegin()->second])
			l.erase(*l.rbegin());
		while (r.size() && vis[r.begin()->second])
			r.erase(*r.begin());

		if (l.size()) {
			int x = l.rbegin()->first;
			int ind = l.rbegin()->second;
			if (point < x) {
				ans += x - point;
				vis[ind] = 1;
				point = x;
				continue;
			}
		}
		if (r.size()) {
			int x = r.begin()->first;
			int ind = r.begin()->second;
			if (point > x) {
				ans += point - x;
				point = x;
				vis[ind] = 1;
				continue;
			}
		}
		ans += abs(point);
		point = 0;
		break;
	}
	ans += abs(point);
	ll ans2 = ans;
	ans = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 0, a, b; i < n; i++) {
		a = X[i], b = Y[i];
		l.insert(make_pair(a, i));
		r.insert(make_pair(b, i));
	}
	point = 0;
	ans = 0;
	for (int i = 0; i < n; i++) {
		while (l.size() && vis[l.rbegin()->second])
			l.erase(*l.rbegin());
		while (r.size() && vis[r.begin()->second])
			r.erase(*r.begin());
		if (r.size()) {
			int x = r.begin()->first;
			int ind = r.begin()->second;
			if (point > x) {
				ans += point - x;
				point = x;
				vis[ind] = 1;
				continue;
			}
		}
		if (l.size()) {
			int x = l.rbegin()->first;
			int ind = l.rbegin()->second;
			if (point < x) {
				ans += x - point;
				vis[ind] = 1;
				point = x;
				continue;
			}
		}
		ans += abs(point);
		point = 0;
		break;
	}
	cout << max(ans + abs(point), ans2) << endl;
	return 0;
}

