
// C - Streamline

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int X[100000];
int d[100000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		cin >> X[i];
	}

	sort(X, X+M);

	for (int i=0; i<M-1; i++) {
		d[i] = X[i+1] - X[i];
	}

	sort(d, d+M-1);

	ll ans = 0;
	for (int i=0; i<M-N; i++) {
		ans += d[i];
	}

	cout << ans << endl;

	return 0;
}