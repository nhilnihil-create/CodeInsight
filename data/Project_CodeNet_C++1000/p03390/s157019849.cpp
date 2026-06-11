#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

using ll = long long;
using namespace std;
typedef unsigned long long ull;
typedef pair<ll, ll>P;

const ll MOD = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()


int main() {
	int q;
	cin >> q;
	for (int i = 0;i < q;i++) {
		ll a, b, ans = 0;
		cin >> a >> b;
		ll c = a*b;
		ll l = 1,r = INF2;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (c / mid > mid)l = mid;
			else r = mid;
		}
		if (r*r >= c)r--;
		if (a != b)ans += r * 2 - 1;
		else ans += r * 2;
		if (r*(r + 1) >= c)ans--;
		if (a == 1 && b == 1)ans = 0;
		cout << ans << endl;
	}
}