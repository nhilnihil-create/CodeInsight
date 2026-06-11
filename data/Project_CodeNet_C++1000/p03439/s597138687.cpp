
// C - Vacant Seat

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int V = 0;
const int M = 1;
const int F = 2;

int conv(string s) {
	if (s == "Vacant") return V;
	else if (s == "Male") return M;
	else return F;
}

int main() {
	int N;
	cin >> N;

	string s;

	cout << 0 << endl << flush;
	cin >> s;
	int t = conv(s);

	if (t == V) return 0;

	int head = t;
	int l = 0;
	int r = N - 1;

	while(1) {
		int m = (l + r + 1) / 2;
		//cout << l << " " << m << " " << r << endl; // **** debug ****
		cout << m << endl << flush;
		cin >> s;
		int t = conv(s);

		if (t == V) return 0;

		if ((m - l) % 2 == 1) {
			if (t == head) {
				r = m;
			} else {
				l = m;
				head = t;
			}
		} else {
			if (t == head) {
				l = m;
			} else {
				r = m;
			}
		}
	}

	return 0;
}