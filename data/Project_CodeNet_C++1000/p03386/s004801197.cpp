#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    if (B - A + 1 <= 2 * K) {
        reps(i, A, B + 1) { cout << i << endl; }
        return 0;
    }

    rep(i, K) { cout << A + i << endl; }

    for (ll i = K - 1; i >= 0; i--) {
        cout << B - i << endl;
    }
    return 0;
}
