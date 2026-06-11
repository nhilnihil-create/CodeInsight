#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	ll ans = 0;
	ll t = min(A, C);
	C -= t;
	ans += t;
	t = min(B, C);
	C -= t;
	if (C > 0) ans++;
	ans += t;
	ans += B;
	cout << ans << endl;
}
