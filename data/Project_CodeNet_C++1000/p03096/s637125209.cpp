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

/*
 * 2 1 3 1 2 3 4 2 4 5 5 2
 * 
 */ 
int add(int x, int y) {
	x += y;
	if (x > MOD)
		x -= MOD;
	return x;
}
const int N = 200 * 1000 + 5;
int main() {
	int n;
	cin >> n;
	vector<int> color(n + 1);
	vector<int> prv(n + 1);
	vector<int> last(N, -1);
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
		prv[i] = (last[color[i]] == -1 ? i : last[color[i]]);
		last[color[i]] = i; 
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = add(dp[i], dp[i - 1]);
		if (i - prv[i] >= 2) {
			dp[i] = add(dp[i], dp[prv[i]]);
		}
	}
	cout << dp[n]; 
}
