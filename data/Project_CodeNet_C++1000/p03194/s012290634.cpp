#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N, P;
	cin >> N >> P;

	vector<pair<int64_t, int64_t>> v;
	for (int64_t i = 2; i * i <= P; i++) {
		if (P % i) continue;
		int64_t c = 0;
		while (P % i == 0) {
			c++;
			P /= i;
		}
		pair<int64_t, int64_t> p = { i,c };
		v.push_back(p);
	}
	if (P != 1) {
		pair<int64_t, int64_t> p = { P,1 };
		v.push_back(p);
	}

	int64_t ans = 1;
	for (int64_t i = 0; i < v.size(); i++) {
		int64_t p, c;
		tie(p, c) = v.at(i);
		//cout << p << ' ' << c << endl;
		for (int64_t j = 0; j < c / N; j++) ans *= p;
	}

	cout << ans << endl;
}