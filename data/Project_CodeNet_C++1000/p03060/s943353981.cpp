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

	vector<int> V(N), C(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	for (int i = 0; i < N; i++) cin >> C[i];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int v, c;
		v = V[i];
		c = C[i];
		if (v > c) ans += v - c;
	}

	cout << ans << endl;
}