#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int T, A;
	cin >> T >> A;
	T *= 1000;
	A *= 1000;
	int H[N];
	for(int i = 0; i < N; i++) cin >> H[i];

	int ans = 0;
	int best = inf;
	for(int i = 0; i < N; i++) {
		if(abs(A - T + 6 * H[i]) <= best) {
			best = abs(A - T + 6 * H[i]);
			ans = i;
		}
	}
	cout << ans + 1;
	return 0;
}
