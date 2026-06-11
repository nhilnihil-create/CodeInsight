#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
#define REP(i, n)    for (i64 (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (i64 (i) = (a); (i) < (b); ++(i))

int N;
vector<int> A;
bitset<4004004> dp;

signed main() {

    cin >> N;

    A.resize(N);
    REP(i, N) cin >> A[i];

    dp[0] = 1;
    REP(i, N) dp |= dp << A[i];

    ui64 sum = 0;
    REP(i, N) sum += A[i];

    // 中央値はsumの半分(切り上げ)以上
    FOR(i, (sum + 1) / 2, sum + 1) {
        if (dp[i]) {
            cout << i << endl;
            return 0;
        }
    }

}