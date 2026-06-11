#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int K;
	string S;
	cin >> S >> K;

	if (S.size() == 1) {
		cout << S << endl;
	}
	else {
		if (K == 1) cout << S.front() << endl;
		else {
			int n = -1;
			for (int i = 0; i < S.size(); i++) {
				if (S.at(i) != '1') {
					n = i + 1;
					break;
				}
			}
			//cout << "n:" << n << endl;

			if (n == -1) cout << 1 << endl;
			else {
				if (K < n) cout << S.at(K - 1) << endl;
				else cout << S.at(n - 1) << endl;
			}
		}
	}
}