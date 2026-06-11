#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int Q;
	cin >> Q;

	vector<bool> f(100001);
	vector<int> c(100001);

	for (int i = 2; i < 100001; i++) {
		if (!f.at(i)) {
			for (int j = i * 2; j < 100001; j += i) {
				f.at(j) = true;
			}
		}
	}

	for (int i = 3; i < 100001; i+=2) {
		if (!f.at(i) && !f.at((i + 1) / 2)) c.at(i)++;
	}

	for (int i = 3; i < 100001; i++) {
		c.at(i) += c.at(i - 1);
	}

	for (int i = 0; i < Q; i++) {
		int L, R;
		cin >> L >> R;

		cout << c.at(R) - c.at(L - 1) << endl;
	}
}