#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> arr;
typedef vector<arr> matrix;
typedef vector<ll> longarr;
typedef vector<longarr> longmat;
typedef map<int, arr> graph;
typedef vector<char> chararr;
typedef vector<chararr> charmat;
typedef pair<int, int> fraction;
ll MOD = 1000000007;
int n;
struct segmenttree {
	vector<ll> st;
	int n;

	void init(int _n) {
		n = _n;
		st.clear();
		st.resize(4 * _n);
	}

	void update(int l, int r, int indup, ll val, int node) {
		if (l == r) {
			st[node] = val;
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = max(st[2 * node + 1], st[2 * node + 2]);
		}
	}

	ll query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return 0;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		ll q1 = query(si, mid, l, r, node * 2 + 1);
		ll q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return max(q1, q2);
	}
	ll query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}
	void update(int index, ll val) {
		update(0, n - 1, index, val, 0);
	}
};

int main() {

	segmenttree tree;
	cin >> n;
	vector<pair<int, int> >v;
	vector<ll> b(n, 0);
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		v.push_back({x, i});
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(v.begin(), v.end());
    ll ans=0;
    tree.init(n);
	for (auto p : v) {
        ll val=tree.query(0, p.second - 1) + b[p.second];
		ans = max(ans, val);
		tree.update(p.second, val);
	}

	cout << ans;
}
