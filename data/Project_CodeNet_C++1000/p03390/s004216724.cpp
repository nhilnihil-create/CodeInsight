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
		ll a, b, c, ans = 0;
		cin >> a >> b;
		c = a*b;
		ll s = sqrt(c);
		if (s*s >= c)s--;
		ans += s * 2;
		if (s*(s + 1) >= c)ans--;
		if (a != b)ans--;
		cout << ans << endl;
	}
}