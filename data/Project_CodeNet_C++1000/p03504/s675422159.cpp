#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <bitset>

using namespace std;
using BIT = bitset<30>;

const int max_time = 1e5;

int main() {
	int N, C;
	cin >> N >> C;

	vector<BIT> records(max_time + 1, 0);

	int s, t, c;
	for (int i = 0; i < N; i++) {
		cin >> s >> t >> c;
		for (int i = s; i <= t; i++) {
			records[i].set(c - 1);
		}
	}

	int ans = 0;
	for (int i = 0; i <= max_time; i++) {
		int x = records[i].count();
		ans = max(ans, x);
	}

	cout << ans << endl;

	// for (int i = 0; i <= 100; i++) {
	// 	printf("%3d: %s %2d\n", i, records[i].to_string().substr(25).c_str(), (int)records[i].count());
	// }
	return 0;
}
