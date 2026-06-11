#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N;
	cin >> N;

	vector<int64_t> v(N);
	int64_t s = 0, cnt = 0, m = INT_MAX;

	for (int64_t i = 0; i < N; i++) {
		int64_t n;
		cin >> n;
		v[i] = n;
		if (n < 0) {
			cnt++;
			n *= -1;
		}
		m = min(m, n);
		s += n;
	}

	if (cnt % 2 == 0) cout << s << endl;
	else cout << s - m * 2 << endl;
}