#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int N;
    cin >> N;

    vector<ll> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        chmin(dp[i + 1], dp[i] + 1);
        ll s = 6;
        while (s <= N) {
            if (i + s <= N) {
                chmin(dp[i + s], dp[i] + 1);
            }
            s *= 6;
        }
        ll n = 9;
        while (n <= N) {
            if (i + n <= N) {
                chmin(dp[i + n], dp[i] + 1);
            }
            n *= 9;
        }
    }

    cout << dp[N] << endl;

    return 0;
}