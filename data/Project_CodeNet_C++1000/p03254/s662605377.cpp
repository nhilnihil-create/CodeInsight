#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;


int main() {
	int N, x;
	cin >> N >> x;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int ans;
	for (ans = 0; ans < N; ans++) {
		if (a[ans] <= x) {
			x -= a[ans];
		}
		else {
			cout << ans << endl;
			return 0;
		}
	}

	cout << (x == 0 ? N : N - 1 )<< endl;

}