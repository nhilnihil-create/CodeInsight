#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int bits = 32;
int main() {
	int N;
	cin >> N;
	int bit = 0;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
		bit |= 1 << ((X[i] ^ Y[i]) & 1);
	}
	if (bit == 3) {
		cout << -1 << endl;
	}
	else {
		cout << bits + (bit == 1 ? 1 : 0) << endl;
		vector<long long> d;
		if (bit == 1) cout << 1 << ' ';
		for (int i = bits - 1; i >= 0; --i) {
			cout << (1LL << i);
			if (i) cout << ' ';
			else cout << endl;
		}
		for (int i = 0; i < N; ++i) {
			string ans;
			if (bit == 1) {
				ans += "R"; --X[i];
			}
			for (int j = bits - 1; j >= 0; --j) {
				long long vl = abs(X[i] + (1LL << j)) + abs(Y[i]);
				long long vr = abs(X[i] - (1LL << j)) + abs(Y[i]);
				long long vd = abs(X[i]) + abs(Y[i] + (1LL << j));
				long long vu = abs(X[i]) + abs(Y[i] - (1LL << j));
				long long vm = min({ vl, vr, vd, vu });
				if (vl == vm) X[i] += 1LL << j, ans += "L";
				if (vr == vm) X[i] -= 1LL << j, ans += "R";
				if (vd == vm) Y[i] += 1LL << j, ans += "D";
				if (vu == vm) Y[i] -= 1LL << j, ans += "U";
			}
			cout << ans << endl;
		}
	}
	return 0;
}