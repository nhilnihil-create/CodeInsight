#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
typedef pair<P, int> E;
int main() {
	int L;
	cin >> L;
	int r = 0;
	int x = 1;
	while (x * 2 <= L) {
		x *= 2;
		r++;
	}
	vector<E> ans;
	for (int i = 0; i < r; i++) {
		ans.emplace_back(P(i, i + 1), 0);
		ans.emplace_back(P(i, i + 1), 1 << i);
	}
	for (int i = r - 1; i >= 0; i--) {
		if (L - (1 << i) >= (1 << r)) {
			ans.emplace_back(P(i, r), L - (1 << i));
			L -= (1 << i);
		}
	}
	cout << (r + 1) << " " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " " << ans[i].second << endl;
	}
}
