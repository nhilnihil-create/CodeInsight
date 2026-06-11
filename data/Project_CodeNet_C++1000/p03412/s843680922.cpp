#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second



int main() {
	ll n, a[200010], b[200010], ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++)cin >> a[i];
	for (int i = 0;i < n;i++)cin >> b[i];
	for (int i = 0;i <= 28;i++) {
		ll c[200010],d[200010];
		for (int j = 0;j < n;j++)c[j] = a[j] % (1 << (i + 1));
		for (int j = 0;j < n;j++)d[j] = b[j] % (1 << (i + 1));
		sort(d, d + n);
		ll count1 = 0;
		for (int j = 0;j < n;j++) {
			int it = lower_bound(d, d + n, (1 << i) - c[j]) - d;
			int it2 = lower_bound(d, d + n, (1 << i) * 2 - c[j]) - d;
			count1 += max(0, it2 - it);
			it = lower_bound(d, d + n, (1 << i) * 3 - c[j]) - d;
			it2 = lower_bound(d, d + n, (1 << i) * 4 - c[j]) - d;
			count1 += max(0, it2 - it);
		}
		if (count1 % 2 == 1)ans += 1 << i;
	}
	cout << ans << endl;
	return 0;
}