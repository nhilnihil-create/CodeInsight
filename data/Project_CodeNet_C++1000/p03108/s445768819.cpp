#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class UFDS {

public:
	// this function initializes the UFDS
	UFDS(ll n) {
		par.resize(n);
		sz.resize(n);
		for (ll i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	//  this function returns the representative of the group that item x is in
	ll find(ll x) {
		if (par[x] == x) {
			return x;
		}
		else {
			// path compression: link x -> representative of the group directly
			// recursively follow the arrows up to the representative
			par[x] = find(par[x]);
			return par[x];
		}
	}

	// this function combines the groups items x and y are in
	void merge(ll x, ll y) {
		// find the representatives of the two groups
		x = find(x);
		y = find(y);
		if (x == y) {
			return;
		}
		par[x] = y; // x -> y
		sz[y] += sz[x]; // number of items in group y has increased by the number of items in group x
		return;
	}

	// this function returns the size of the group item x is in
	ll get_size(ll x) {
		return sz[find(x)];
	}

	// this function returns true if items x and y are in the same set
	bool same_set(ll x, ll y) {
		return find(x) == find(y);
	}

private:
	vector<ll> par;
	// par[i] is the 'parent' of item i
	// i -> par[i]
	vector<ll> sz;
	// sz[i] stores the number of items in group i
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	UFDS data(n);

	vector<pair<ll, ll>> bridges(m);
	ll ans = (n) * (n - 1) / 2;
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		bridges[i] = make_pair(x - 1, y - 1);
	}
	vector<ll> answers(m);
	for (int i = m - 1; i >= 0; i--) {
		answers[i] = ans;
		//backwards merge
		ll x = bridges[i].first;
		ll y = bridges[i].second;
		if (data.same_set(x, y)) {
			// Do nothing
			continue;
		}
		ll size_x = data.get_size(x);
		ll size_y = data.get_size(y);
		ans += (size_x) * (size_x - 1) / 2;
		ans += (size_y) * (size_y - 1) / 2;
		ll new_sz = size_x + size_y;
		ans -= (new_sz) * (new_sz - 1) / 2;
		data.merge(x, y);
	}
	for (int i = 0; i < m; i++) {
		cout << answers[i] << '\n';
	}
}