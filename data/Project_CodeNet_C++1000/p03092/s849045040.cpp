/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int N, cost_r, cost_l;
    cin >> N >> cost_r >> cost_l;
    vector<int> A(N);
    vector<int> num2pos(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        num2pos[A[i]] = i;
    }

    int dp[N+1][N]; // 数字iを区間jにおいたときのコストの最小値
    for (int i = 0; i < N; i++) dp[0][i] = 0;

    // dp[i+1][j] = min(dp[i][0], ..., dp[i][j]) + cost;
    for (int i = 0; i < N; i++) {
        int mn = INF;
        for (int j = 0; j < N; j++) {
            mn = min(mn, dp[i][j]);
            int cost;
            if (num2pos[i + 1] == j) cost = 0;
            else if (num2pos[i + 1] > j) cost = cost_l;
            else cost = cost_r;
            dp[i+1][j] = mn + cost;
        }
    }

    int ret = INF;
    for (int j = 0; j < N; j++) ret = min(ret, dp[N][j]);
    cout << ret << endl;

    return 0;
}