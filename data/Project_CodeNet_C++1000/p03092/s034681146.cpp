/*input
9 40 50
5 3 4 7 6 1 2 9 8
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 5007;
const ll INF = 1e17;
ll cost[MAXN][MAXN], dp[MAXN], A, B;
int arr[MAXN], N;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> A >> B;
	FOR(i, 1, N) cin >> arr[i];

	arr[N + 1] = N + 1;
	FOR(i, 0, N) {
		ll cur = 0;
		FOR(j, i + 1, N + 1) {
			cost[i][j] = cur;
			cur += (arr[i] < arr[j] ? A : B);
		}
	}

	FOR(i, 1, N + 1) {
		dp[i] = INF;
		FOR(j, 0, i - 1) if (arr[j] < arr[i]) {
			dp[i] = min(dp[i], dp[j] + cost[j][i]);
		}
	}

	cout << dp[N + 1] << endl;

	return 0;
}
