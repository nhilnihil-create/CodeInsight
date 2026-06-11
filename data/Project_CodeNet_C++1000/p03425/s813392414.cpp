#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(5);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s.at(0) == 'M') v.at(0)++;
		if (s.at(0) == 'A') v.at(1)++;
		if (s.at(0) == 'R') v.at(2)++;
		if (s.at(0) == 'C') v.at(3)++;
		if (s.at(0) == 'H') v.at(4)++;
	}

	int64_t ans = 0;
	for (int bit = 1; bit < (1 << 5); bit++) {
		bitset<5> bs(bit);
		if (bs.count() != 3) continue;

		int64_t n = 1;
		for (int i = 0; i < 5; i++) {
			if (bs[i]) n *= v.at(i);
		}

		ans += n;
	}

	cout << ans << endl;
}