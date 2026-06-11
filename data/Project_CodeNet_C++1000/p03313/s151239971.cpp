#include <bits/stdc++.h>
using namespace std;

const int MAXN = 18;
const int MAXM = 1 << MAXN;
int N;
int M;

int A[MAXM];

int ans[MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	M = 1 << N;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}

	for (int m = 0; m < M; m++) {
		int v[2] = {};
		for (int s = m; true; s = (s-1) & m) {
			if (A[s] > v[0]) {
				v[1] = v[0];
				v[0] = A[s];
			} else if (A[s] > v[1]) {
				v[1] = A[s];
			}
			if (s == 0) break;
		}
		ans[m] = v[0] + v[1];
	}

	for (int m = 1; m < M; m++) {
		ans[m] = max(ans[m], ans[m-1]);
	}

	for (int m = 1; m < M; m++) {
		cout << ans[m] << '\n';
	}

	return 0;
}