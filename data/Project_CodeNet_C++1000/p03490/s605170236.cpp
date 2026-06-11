#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define all(a) a.begin(), a.end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define endl '\n'

const int offset = 8e3 + 5, N = offset - 5;
bool dp[N + 5][3 * offset + 10];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();

	string s;
	int x, y;
	cin >> s >> x >> y;
	int nn = s.size(), cnt = 0;
	s = ' ' + s;
	vector <int> a;
	FORD(i, nn, 1) {
		if (s[i] == 'F') cnt++;
		else {
			a.push_back(cnt);
			cnt = 0;
		}
	}
	int n = a.size();
	if (n == 0) {
		if (x == cnt && y == 0) cout << "Yes"; else cout << "No";
		return 0;
	}
	a.push_back(0); reverse(a.begin(), a.end());
	memset(dp, 0, sizeof dp);
	dp[0][cnt + offset] = 1;
	dp[1][a[1] + offset] = dp[1][-a[1] + offset] = 1;
	FOR(i, 2, n) FOR(j, -N, N) {
		if (abs(j + a[i]) <= nn) dp[i][j + offset] |= dp[i - 2][j + a[i] + offset];
		if (abs(j - a[i]) <= nn) dp[i][j + offset] |= dp[i - 2][j - a[i] + offset];
	}
	if (n & 1) dp[n][x + offset] = dp[n - 1][x + offset];
	else dp[n][y + offset] = dp[n - 1][y + offset];
	if (dp[n][x + offset] && dp[n][y + offset]) cout << "Yes"; else cout << "No";
	
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
