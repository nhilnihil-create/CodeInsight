#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

#define x first
#define y second

pair<ll, ll> p[50];
pair<ll, ll> q[2500];

int main()
{
	int N, K;
	ll ans = (ll)4 * (ll)1e18;

	cin >> N >> K;
	rep(i, N) cin >> p[i].x >> p[i].y;

	rep(i, N) rep(j, N) {
		q[i * N + j].x = p[i].x;
		q[i * N + j].y = p[j].y;
	}

	repc(i, 0, N * N - 2) repc(j, i + 1, N * N - 1) {
		int cnt = 0;
		ll xmin = min(q[i].x, q[j].x);
		ll xmax = max(q[i].x, q[j].x);
		ll ymin = min(q[i].y, q[j].y);
		ll ymax = max(q[i].y, q[j].y);

		rep(s, N) {
			if ((xmin <= p[s].x && p[s].x <= xmax) &&
				(ymin <= p[s].y && p[s].y <= ymax)) cnt++;
		}

		if (cnt >= K) ans = min(ans, (xmax - xmin) * (ymax - ymin));
	}

	cout << ans << endl;

	return 0;
}
