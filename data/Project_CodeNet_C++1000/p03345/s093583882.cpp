#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
	int a, b, c;
	ll k;
	cin >> a >> b >> c >> k;
	ll ans;
	if (k % 2 == 0) ans = a - b;
	else ans = b - a;
	if (max(ans, -ans) > 1000000000000000000) cout << "Unfair" << endl;
	else cout << ans << endl;
	return 0;
}