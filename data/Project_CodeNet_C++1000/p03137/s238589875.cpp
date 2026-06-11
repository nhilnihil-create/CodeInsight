#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;

	if (N >= M) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> v(M), dif(M - 1);
	for (int i = 0; i < M; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 1; i < M; i++) dif[i - 1] = abs(v[i] - v[i - 1]);
	sort(dif.begin(), dif.end());

	int n = M - N;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dif[i];
	}
	cout << sum << endl;
}