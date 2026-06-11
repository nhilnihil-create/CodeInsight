#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct comp {
	int mod;
	comp(int x) : mod(x) {}
	bool operator()(const int& a, const int& b) const {
		return a % mod < b % mod;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (auto&& x : a)cin >> x;
	for (auto&& x : b)cin >> x;
	int ans = 0;
	for (int p = 0; p < 30; ++p) {
		sort(b.begin(), b.end(), comp(1 << p));

		bool btog = false;
		for (int i = 0; i < n; ++i) {
			btog ^= (b[i] >> p) & 1;
		}

		for (int i = 0; i < n; ++i) {
			int val = (1 << p) - (a[i] % (1 << p)) - 1;
			int pos = upper_bound(b.begin(), b.end(), val, comp(1 << p)) - b.begin();
			int pval = (a[i] >> p) & 1;
			bool tog = (pval ? pos & 1 : (n - pos) & 1);
			tog ^= btog;
			if (tog)ans ^= (1 << p);
		}
	}
	cout << ans << '\n';

	return 0;
}
