#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	int ans = 0;
	for (int x = 1; x <= min(n, k); x++) {	
		for (int lx = 0; lx <= x; lx++) {
			int rx = x - lx;
			vector<int> pv, mv;
			for (int i = 0; i < lx; i++) {
				int a = V[i];
				if (a >= 0) pv.push_back(a);
				else mv.push_back(a);
			}
			for (int i = 0; i < rx; i++) {
				int a = V[n-1-i];
				if (a >= 0) pv.push_back(a);
				else mv.push_back(a);
			}
			int z = min((int)mv.size(), k - x);
			sort(mv.begin(), mv.end());
			int now = 0;
			for (int i = z; i < mv.size(); i++) {
				now += mv[i];
			}
			for (int e : pv) {
				now += e;
			}
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}