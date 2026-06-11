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

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    // 速度区間の数は(N+2)
    int N;
    cin >> N;

    // 速度区間の境目の数は(N+1)
    int t[N+1];
    t[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        t[i] += t[i-1];
    }
    int T = t[N];

    // 速度区間の数は(N+2)
    int v[N+2];
    v[0] = 0;
    v[N+1] = 0;
    for (int i = 1; i <= N; i++) cin >> v[i];

    // table[i][j]: i番目の区間による最大値の束縛で, 時間インデックスj番目を表す
    double table[N + 2][2*T + 1];

    for (int i = -1; i <= N; i++) {
        double left = i < 0 ? -1 : t[i];
        double right = i == N ? T + 1 : t[i+1];
        left *= 2;
        right *= 2;

        for (int time = 0; time <= 2*T; time++) {
            if (time < left) {
                table[i+1][time] = v[i+1] + (left - time) * 0.5;
            } else if (time > right) {
                table[i+1][time] = v[i+1] + (time - right) * 0.5;
            } else {
                table[i+1][time] = v[i+1];
            }
        }
    }

    double min_vec[2*T + 1];
    for (int j = 0; j < 2*T + 1; j++) {
        min_vec[j] = table[0][j];
        for (int i = 1; i < N+2; i++) {
            min_vec[j] = min(min_vec[j], table[i][j]);
        }
    }

    double ret = 0;
    for (int i = 0; i < 2*T; i++) {
        ret += abs(min_vec[i] + min_vec[i+1]) * 0.5 * 0.5;
    }

    cout << fixed << setprecision(5) << ret << endl;
}