
// C - Five Transportations

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N, A, B, C, D, E;
	cin >> N >> A >> B >> C >> D >> E;

	ll M = min(A, min(B, min(C, min(D, E))));

	ll ans = 5 + (N-1) / M;

	cout << ans << endl;

	return 0;
}