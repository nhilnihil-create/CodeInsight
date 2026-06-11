#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N, Q;
	string s;
	cin >> N >> s >> Q;
	vector<int> K(Q);
	for (int i = 0; i < Q; ++i) { cin >> K[i]; }

	s = "#" + s;
	vector<Int> cntD(N + 1, 0);
	vector<Int> cntM(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		if (s[i] == 'D') { ++cntD[i]; }
		if (s[i] == 'M') { ++cntM[i]; }
		cntD[i] += cntD[i - 1];
		cntM[i] += cntM[i - 1];
	}

	auto DMC = [&](int k) -> Int {
		int l = 0, r = 1;
		Int ret = 0, sum = 0;
		while (l < r && r <= N) {
			while (r <= N && s[r] != 'C') {
				if (s[r] == 'M') { sum += cntD[r]; }
				++r;
			}
			while (r - l - 1 >= k && l <= N) {
				++l;
				if (s[l] == 'M') { sum -= cntD[l]; }
			}
			if (r > N || l > N) { break; }
			ret += sum - cntD[l] * (cntM[r] - cntM[l]);
			++r;
		}
		return ret;
	};

	for (int k : K) { cout << DMC(k) << endl; }

	return 0;
}
