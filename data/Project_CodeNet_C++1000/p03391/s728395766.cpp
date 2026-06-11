#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>


ll n, ans, c = INF;
bool ok = true;
int main() {
	cin >> n;
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		if (a != b)ok = false;
		ans += b;
		if (a > b)c = min(c, b);
	}
	if (ok)cout << 0 << endl;
	else {
		if (c != INF)ans -= c;
		cout << ans << endl;
	}
}
