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
int powmod(int a, int p, int mod) {
    int ans = 1;
    int mul = a;

    for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
        if ((p & 1) == 1) ans = (ans * mul) % mod;
    }

    return ans;
}

signed main() {
    int N;
    cin >> N;
    int score[N];
    for (int i = 0; i < N; i++) cin >> score[i];

    int fact = 1;
    for (int i = 1; i <= N; i++) {
        fact *= i;
        fact %= MOD;
    }

    int S[N];
    S[0] = 1;
    for (int i = 1; i < N; i++) {
        S[i] = S[i-1] + powmod(i + 1, MOD - 2, MOD);
        S[i] %= MOD;
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret += (((score[i] * fact) % MOD) * (S[i] + S[N - 1 - i] - S[0] + MOD)) % MOD;
        ret %= MOD;
    }

    cout << ret << endl;

    return 0;
}