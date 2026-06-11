#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.141592653589793238

int main() {
	int64_t N;
	cin >> N;
	int digit = to_string(N).size();
	if (digit == 1) {
		cout << N << endl;
		return 0;
	}
	string n = to_string((N + 1) / (int64_t)pow(10, digit - 1) * (int64_t)pow(10, digit - 1) - 1);
	int ans = 0;
	rep(i, n.size()) {
		ans += n[i] - '0';
	}
	cout << ans << endl;
	return 0;
}