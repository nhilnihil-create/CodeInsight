#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<climits>
#include<queue>
 
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;
	long long ans = 0;
	for (int k = 28; k >= 0; k--) {
		long long x = (1 << k);
		sort(a.begin(), a.end());
		int odd = 0;
		for (const auto& e : b) {
			odd += (a.end() - lower_bound(a.begin(), a.end(), x - e)) % 2;
			odd += (a.end() - lower_bound(a.begin(), a.end(), 2 * x - e)) % 2;
			odd += (a.end() - lower_bound(a.begin(), a.end(), 3 * x - e)) % 2;
		}
		// もし奇数なら
		if (odd%2) ans += x;
		for (auto& e : a) e %= x;
		for (auto& e : b) e %= x;
	}
	cout << ans << endl;

	return 0;
}