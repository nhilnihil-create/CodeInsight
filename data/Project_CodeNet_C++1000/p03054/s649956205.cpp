#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7 * 17 * (1 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int w, h, n, x, y;
string a, b;
bool go(char aa, char bb, int z, int r, int ai, int bi) {
	for (int i = 0; i < n; i++) {
		if (a[i] == aa)
			z += ai;
		if (z < 1 || z > r)
			return true;
		if (b[i] == bb)
			z = max(1, min(z + bi, r));
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> w >> h >> n >> x >> y >> a >> b;
	bool c = go('L', 'R', y, h, -1, 1) || go('R', 'L', y, h, 1, -1)
			|| go('U', 'D', x, w, -1, 1) || go('D', 'U', x, w, 1, -1);
	cout << (c?"NO":"YES");
	return 0;
}
