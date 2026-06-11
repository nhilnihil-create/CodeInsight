#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	ll n;
	cin >> n;
	for (int h = 1; h <= 3500; h++) {
		for (int w = 1; w <= 3500; w++) {
			ll nume = (n * h * w);
			ll deno = (4 * h * w - n * (h + w));
			if (deno <= 0 || nume % deno != 0) continue;
			cout << h << " " << w << " " << nume / deno << endl;
			return;
	}
	}
}

int main() {
	solve();
	return 0;
}