
// C - Attention

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	int E = 0;
	for (int i=0; i<N; i++) {
		if (S[i] == 'E') E++;
	}

	int LW = 0;
	int RE = E;

	int ans = INF;
	for (int i=0; i<N; i++) {
		if (i > 0 && S[i-1] == 'W') LW++;
		if (S[i] == 'E') RE--;
		ans = min(ans, LW + RE);
	}

	cout << ans << endl;

	return 0;
}