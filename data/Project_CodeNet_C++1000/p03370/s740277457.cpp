#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<int>M(N);
	int nmin = 1e9;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		nmin = min(nmin, num);
		ans++;
		X -= num;
	}
	ans += X / nmin;
	cout << ans << endl;
}
