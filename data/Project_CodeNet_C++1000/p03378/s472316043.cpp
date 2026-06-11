#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M, X;
	cin >> N >> M >> X;

	vector<bool> v(N + 1);
	int L, R;
	L = 0;
	R = 0;

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		if (n < X) L++;
		else R++;
	}

	cout << min(L, R) << endl;
}