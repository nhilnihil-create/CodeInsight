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

	vector<vector<bool>> v(M,vector<bool>(10));
	vector<int> p(M);

	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int n;
			cin >> n;
			v[i][n - 1] = 1;
		}
	}
	for (int i = 0; i < M; i++) cin >> p[i];

	int cnt = 0;
	for (int i = 0; i < (1 << N); i++) {
		bool f = 1;

		for (int j = 0; j < M; j++) {
			int c = 0;

			for (int k = 0; k < N; k++) {
				if (i & (1 << k)) {
					if (v[j][k]) c++;
				}
			}

			int n = c % 2;
			if (n != p[j]) f = 0;
		}

		if (f) cnt++;
	}

	cout << cnt << endl;
}