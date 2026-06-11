#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<vector<bool>> F(N, vector<bool>(10));
	vector<vector<int>> P(N, vector<int>(11));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			bool b;
			cin >> b;
			F.at(i).at(j) = b;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 10; j++) {
			int n;
			cin >> n;
			P.at(i).at(j) = n;
		}
	}

	int ans = INT_MIN;
	vector<int> c(N);

	for (int bit = 1; bit < (1 << 10); bit++) {
		//cout << bitset<10>(bit) << endl;
		for (int i = 0; i < N; i++) c.at(i) = 0;

		for (int i = 0; i < 10; i++) {
			if (bit & (1 << i)) {
				for (int j = 0; j < N; j++) {
					if (F.at(j).at(i)) c.at(j)++;
				}
			}
		}
		//for (int i = 0; i < N; i++) cout << c.at(i) << endl;

		int n = 0;
		for (int i = 0; i < N; i++) {
			//cout << P.at(i).at(c.at(i)) << endl;
			n += P.at(i).at(c.at(i));
		}
		//cout << "n:" << n << endl;

		ans = max(ans, n);
		//cout << ans << endl;
	}

	cout << ans << endl;
}