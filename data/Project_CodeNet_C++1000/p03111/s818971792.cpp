#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int N, A, B, C;
vector<int> L;

void chmin(int& a, int b) {
	if (a > b) a = b;
}

int rec(int i, int a, int b, int c) {
	if (i == N) {
		if (!a || !b || !c) return 1e9;
		else {
			int sum = abs(A - a) + abs(B - b) + abs(C - c);
			//cout << sum << endl;
			return sum;
		}
	}

	int res = rec(i + 1, a, b, c);
	chmin(res, rec(i + 1, a + L[i], b, c) + (a ? 10 : 0));
	chmin(res, rec(i + 1, a, b + L[i], c) + (b ? 10 : 0));
	chmin(res, rec(i + 1, a, b, c + L[i]) + (c ? 10 : 0));

	return res;
}

int main() {
	cin >> N >> A >> B >> C;

	L.resize(N);
	for (int i = 0; i < N; i++) cin >> L[i];

	int ans = rec(0, 0, 0, 0);

	cout << ans << endl;
}