#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct cmp {
	int mod;
	cmp(int x) :mod(x) {}
	bool operator()(const int& a, int& b)const {
		return a % mod < b % mod;
	}
};

int main() {
	int n; cin >> n;
	vector<int>a(n), b(n); for (auto&& x : a)cin >> x; for (auto&& x : b)cin >> x;
	int ans = 0;
	for (int i = 0; i < 30; i++) {
		sort(b.begin(), b.end(), cmp(1 << i));
		bool btg = false;
		for (int j = 0; j < n; j++) {
			btg ^= (b[j] >> i) & 1;
		}
		for (int j = 0; j < n; j++) {
			int v = (1 << i) - (a[j] % (1 << i)) - 1;
			int pos = upper_bound(b.begin(), b.end(), v, cmp(1 << i)) - b.begin();
			int pv = (a[j] >> i) & 1;
			bool tg = (pv ? pos & 1 : (n - pos) & 1);
			tg ^= btg;
			if (tg)ans ^= (1 << i);
		}
	}
	cout << ans << endl;
	return 0;
}