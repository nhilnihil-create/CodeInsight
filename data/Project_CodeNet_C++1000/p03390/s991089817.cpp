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
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int q;
	cin >> q;
	while(q--) {
		ll a, b;
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		ll ans = 2 * a - 2;
		ll c = (ll) sqrt(a * b);
		if(c * (c + 1) < a * b) {
			ans = max(ans, 2 * c - 1);
		}
		else {
			if(c * c == a * b)
				ans = max(ans, 2 * c - 3);
			else
				ans = max(ans, 2 * c - 2);
		}
		cout << ans << "\n";
	}
}
