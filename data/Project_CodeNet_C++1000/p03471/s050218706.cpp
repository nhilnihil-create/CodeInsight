#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	int N;
	int Y;
	cin >> N >> Y;

	int sum = 0;
	int cnt[3] = { 0, 0, 0 };

	while (Y >= sum) {
		sum += 10000;
		cnt[0] += 1;
	}

	sum -= 10000;
	cnt[0] -= 1;

	while (Y >= sum) {
		sum += 5000;
		cnt[1] += 1;
	}

	sum -= 5000;
	cnt[1] -= 1;

	while (Y != sum) {
		sum += 1000;
		cnt[2] += 1;
	}

	if (cnt[0] + cnt[1] + cnt[2] == N) {
		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
	}
	else if (cnt[0] + cnt[1] + cnt[2] < N) {
		bool frag = false;
		int ans[3] = { 0, 0, cnt[2] };
		int val = 0;
		for (int j = 0; j <= cnt[0]; j++) {
			for (int i = 0; i <= cnt[1] + 2 * j; i++) {
				val = cnt[2] + cnt[1] + 2 * j + cnt[0] - j - i + 5 * i;
				if (val == N) {
					ans[0] = cnt[0] - j;
					ans[1] = cnt[1] + 2 * j - i;
					ans[2] = cnt[2] + 5 * i;
					cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
					return 0;
				}
			}
		}
		cout << -1 << " " << -1 << " " << -1 << endl;
	}
	else {
		cout << -1 << " " << -1 << " " << -1 << endl;
	}



	return 0;
}