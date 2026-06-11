// Comment
// Choose number of (A+B) first

#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

int A, B, C, X, Y;
int main() {
	cin >> A >> B >> C >> X >> Y;
	ll ans = LINF;
	for(int i=0; i<=max(X, Y); i++) {
		ans = min(ans, 1ll * max(0, X-i) * A + 1ll * max(0, Y-i) * B + 1ll * 2 * i * C);
	}
	cout << ans << endl;
	return 0;
}
