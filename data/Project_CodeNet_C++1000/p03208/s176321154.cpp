
// C - Christmas Eve

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int h[100000];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> h[i];
	}

	sort(h, h+N);

	int ans = INF;

	for (int i=0; i+K-1<N; i++) {
		ans = min(ans, h[i+K-1] - h[i]);
	}

	cout << ans << endl;

	return 0;
}