#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; i += 2) {
		int r = sqrt(i);
		int cnt = 2;

		for (int j = r; j > 1; j--) {
			if ((j * j) == i) cnt++;
			else {
				int n = i / j;
				if ((n * j) == i) cnt += 2;
			}
		}

		if (cnt == 8) {
			ans++;
			//cout << i << endl;
		}
	}

	cout << ans << endl;
}