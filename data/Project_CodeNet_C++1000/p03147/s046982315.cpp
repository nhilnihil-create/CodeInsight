#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<int> h(N);
	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		x = max(x, h[i]);
	}
	//cout << x << endl;

	int ans = 0;
	for (int n = 1; n <= x; n++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (h[i] >= n) {
				cnt++;
				if (i && (h[i - 1] >= n)) cnt--;
			}
		}
		//cout << n << ':' << cnt << endl;
		ans += cnt;
	}

	cout << ans << endl;
}