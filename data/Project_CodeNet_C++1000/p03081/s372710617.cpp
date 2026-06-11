#include <bits/stdc++.h>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for (T& x : v) { is >> x; }
	return is;
}

int n, q;
string s;
bool C_left(vector<pair<char, char>>& a, int idx) {
	rep(i, q) {
		if (s[idx] == a[i].first) { idx = idx + (a[i].second == 'R' ? 1 : -1); }
		if (idx < 0) return true;
		if (idx >= n) return false;
	}
	return false;
}
bool C_right(vector<pair<char, char>>& a, int idx) {
	rep(i, q) {
		if (s[idx] == a[i].first) { idx = idx + (a[i].second == 'R' ? 1 : -1); }
		if (idx < 0) return false;
		if (idx >= n) return true;
	}
	return false;
}

signed main() {
	cin >> n >> q >> s;

	vector<pair<char, char>> a(q);
	rep(i, q) {
		char s, t;
		cin >> s >> t;
		a[i] = make_pair(s, t);
	}

	//rep(i, n) { cout << i << ' ' << C_left(a, i) << endl; }
	//rep(i, n) { cout << i << ' ' << C_right(a, i) << endl; }

	int ans_left;
	{
		int right = n, left = 0;
		rep(i, 100) {
			int mid = (right + left) / 2;
			// cout << mid << ' ' << C_left(a, mid) << endl;
			if (C_left(a, mid))
				left = mid;
			else
				right = mid;
		}
		ans_left = left;
	}

	int ans_right;
	{
		int right = n, left = 0;
		rep(i, 100) {
			int mid = (right + left) / 2;
			// cout << mid << ' ' << C_right(a, mid) << endl;
			if (C_right(a, mid))
				right = mid;
			else
				left = mid;
		}
		ans_right = right;
	}
	// cout << ans_left << ' ' << ans_right << endl;

	cout << max(0LL, ans_right - ans_left - 1) << endl;
}
