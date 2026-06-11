
// C - Monsters Battle Royale

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int ans;

	cin >> ans;

	for (int i=1; i<N; i++) {
		int A;
		cin >> A;
		ans = __gcd(ans, A);
	}

	cout << ans << endl;

	return 0;
}