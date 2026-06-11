#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int a, b, c, x,  y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if(2 * c <= (a + b)) {
		ans += min(x, y) * (2 * c);
		int t = min(x, y);
		x -= t;
		y -= t;
		if(x > 0) {
			if(2 * c <= a) {
				ans += x * (2 * c);
			}
			else {
				ans += x * a;
			}
		}
		if(y > 0) {
			if(2 * c <= b) {
				ans += y * (2 * c);
			}
			else {
				ans += y * b;
			}
		}
	}
	else {
		ans += x * a + y * b;
	}
	cout << ans;
}
