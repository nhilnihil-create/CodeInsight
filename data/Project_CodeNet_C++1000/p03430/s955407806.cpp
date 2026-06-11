#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cassert>
#include <tuple>
#include <list>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

template<class htpe, class cmp>
using heap = priority_queue<htpe, vector<htpe>, cmp>;

template<class htpe>
using min_heap = heap<htpe, greater<htpe> >;

template<class htpe>
using max_heap = heap<htpe, less<htpe> >;

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forrn(i, s, n) for (int i = (int)(s); i < ((int)(n)); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))

const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;

const int maxn = 379;
int dp[maxn][maxn][maxn];

int main() {
    // Code here:

    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            for (int t = 0; t <= k; t++) {
                dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][j][t]);
                dp[i][j - 1][t] = max(dp[i][j - 1][t], dp[i][j][t]);
                if (s[i - 1] == s[j - 1]) {
                    dp[i + 1][j - 1][t] = max(dp[i + 1][j - 1][t], dp[i][j][t] + 1);
                } else if (t > 0) {
                    dp[i + 1][j - 1][t - 1] = max(dp[i + 1][j - 1][t - 1], dp[i][j][t] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ans = max(ans, 2 * dp[i][i][j] + 1);
            ans = max(ans, 2 * dp[i][i - 1][j]);
        }
    }

    cout << ans;

    return 0;
}
