#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);
const lli mod = (lli)(998244353);

lli n, a, b, k, fac[N], ans;

lli fp(lli x, lli y) {
	if(y == 0)
		return 1;
	lli t = fp(x, y / 2);
	if(y % 2 == 0)
		return t * t % mod;
	else
		return (t * t % mod) * x % mod;
}

lli comb(lli x, lli y) {
	if(x < y)
		return 0;
	lli den = fac[y] * fac[x - y] % mod;
	return fp(den, mod - 2) * fac[x] % mod;
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);

	cin >> n >> a >> b >> k;

	if(k == 0) {
		cout << 1;
		return 0;
	}

	fac[0] = 1;
	for(lli i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i % mod;
	for(lli x = 0; x <= n; x++) {
		if((k - x * a) % b == 0) {
			lli y = (k - x * a) / b;
			if(y >= 0 && y <= n) {
				ans += comb(n, x) * comb(n, y) % mod;
				ans %= mod;
				// d1("asd");
			}
		}
	}
	cout << ans;
}