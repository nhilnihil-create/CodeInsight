#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> t(N + 1), x(N + 1), y(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> t.at(i) >> x.at(i) >> y.at(i);
	}

	//for (int i = 0; i <= N; i++) {
	//	cout << t.at(i) << ' ';
	//	cout << x.at(i) << ' ';
	//	cout << y.at(i) << endl;
	//}

	bool f = true;

	for (int i = 1; i <= N; i++) {
		int n, a, b;
		n = t.at(i) - t.at(i - 1);
		a = abs(x.at(i) - x.at(i - 1));
		b = abs(y.at(i) - y.at(i - 1));

		if (n < a + b) {
			f = false;
			break;
		}
		else if (n > a + b) {
			if ((n - a - b) % 2) {
				f = false;
				break;
			}
		}
	}

	cout << (f ? "Yes" : "No") << endl;
}