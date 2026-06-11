#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, t, a; cin >> n >> t >> a;
	vector<int>h(n); for (auto&& x : h)cin >> x;
	
	int ans = 0;
	double tmp = 1 << 20;
	for (int i = 0; i < n; i++) {
		double t_now =  t - h[i] * 0.006;
		if (abs(a - t_now) < abs(a - tmp)) {
			ans = i+1;
			tmp = t_now;			
		}
	}
	cout << ans << endl;

	return 0;
}