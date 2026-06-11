#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	double ave = 0;
	rep(i, N) {
		cin >> a.at(i);
		ave += a.at(i);
	}
	ave /= N;
	int ans = 0;
	for (int i = 1;i < N;++i) {
		if (abs(a.at(i) - ave) < abs(a.at(ans) - ave)) ans = i;
	}
	cout << ans << endl;
	return 0;
}