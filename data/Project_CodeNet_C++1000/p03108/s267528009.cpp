#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;
class DSU {
	private:
		int *data;
	public:
		DSU(int n) {
			data = new int[n];
			for(int i = 0; i < n; i++) {
				data[i] = -1;
			}
		}

		~DSU() {delete[] data;}

		// path compression without recursion
		int find(int i) {
			int parent;
			int back_to = -1;
			for(; (parent = data[i]) >= 0; i = parent) {
				data[i] = back_to;
				back_to = i;
			}
			int root = i;
			while(back_to != -1) {
				i = back_to;
				back_to = data[i];
				data[i] = root;
			}
			return root;
		}

		// union by size
		// returns 0 if union not performed
		// note that 'union' is reserved word
		int merge(int i, int j) {
			int ri = find(i), rj = find(j);
			if (ri == rj)
				return 0;
			if (data[ri] > data[rj]) {
				int t = ri;
				ri = rj;
				rj = t;
			}
			data[ri] += data[rj];
			data[rj] = ri;
			return 1;
		}

		int get_size(int i) {
			return -data[find(i)];
		}
};
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		a[i] = --ai;
		b[i] = --bi;
	}
	DSU d(n);
	vector<ll> ans(m);
	ll now = (ll)n * (n - 1) / 2;
	for(int i = m - 1; i >= 0; i--) {
		ans[i] = now;
		if (d.find(a[i]) != d.find(b[i])) {
			now -= d.get_size(a[i]) * d.get_size(b[i]);
			d.merge(a[i], b[i]);
		}
	}
	rep(i, m) cout << ans[i] << endl;
}
