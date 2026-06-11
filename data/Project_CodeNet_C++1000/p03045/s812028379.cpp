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
	DSU d(n);
	rep(i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		d.merge(x, y);
	}
	vector<int> id(n);
	rep(i, n) id[i] = d.find(i);
	sort(id.begin(), id.end());
	id.erase(unique(id.begin(), id.end()), id.end());
	cout << id.size() << endl;
	
}
