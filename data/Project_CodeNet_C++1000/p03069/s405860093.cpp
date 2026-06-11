
// C - Stones

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int B[200001];

int main() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	for (int i=0; i<N; i++) {
		B[i+1] = B[i] + (S[i] == '#' ? 1 : 0);
	}

	int ans = INF;

	for (int i=0; i<=N; i++) {
		int b = B[i];
		int w = (N - i) - (B[N] - B[i]);
		//cout << b + w << endl; // **** debug ****
		ans = min(ans, b + w);
	}

	cout << ans << endl;

	return 0;
}