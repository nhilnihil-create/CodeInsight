#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int n, y; cin >> n >> y;
	int a{}, b{}, c{};
	bool works = false;
	F0R(i, n + 1) {
		F0R(j, n + 1) {
			if (10000 * i + 5000 * j + 1000 * (n - i - j) == y) {
				a = i;
				b = j;
				c = n - a - b;
				works = true;
				break;
			}
		}
	}
	if (a < 0 || b < 0 || c < 0) works = false;
	if (works) cout << a << " " << b << " " <<  c << nl;
	else cout << -1 << " " << -1 << " " << -1 << nl;
}