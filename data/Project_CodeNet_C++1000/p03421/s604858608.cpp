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
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>


ll n, a, b, now;
bool rev = false;
vector<ll> ans;
int main() {
	cin >> n >> a >> b;
	if (a + b - 1 > n) {
		cout << -1 << endl;
		return 0;
	}
	if (a < b) {
		swap(a, b);
		rev = true;
	}
	if (b == 1) {
		if(a != n) cout << -1 << endl;
		else {
			REP(i, n)ans.push_back(i + 1);
			if (rev)reverse(ALL(ans));
			REP(i, ans.size()) {
				if (i != 0)cout << " ";
				cout << ans[i];
			}
		}
		return 0;
	}
	if ((n - a + b - 2) / (b - 1) > a) {
		cout << -1 << endl;
		return 0;
	}
	now = n - a;
	FOR(i, n - a + 1, n + 1)ans.push_back(i);
	REP(i, b - 1) {
		ll s = (n - a) / (b - 1);
		if ((n - a) % (b - 1) > i)s++;
		FOR(j, now - s + 1, now + 1)ans.push_back(j);
		now -= s;
	}
	if (rev)reverse(ALL(ans));
	REP(i, ans.size()) {
		if (i != 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}


