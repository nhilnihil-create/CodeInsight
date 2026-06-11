#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	multiset<int> d;
	rep(i, 0, n) {
		int t; cin >> t;
		d.insert(t);
	}

	int m; cin >> m;
	rep(i, 0, m) {
		int t; cin >> t;
		auto it = d.find(t);
		if (it == d.end()) {
			cout << "NO" << endl;
			return 0;
		}
		d.erase(it);
	}

	cout << "YES" << endl;
}
