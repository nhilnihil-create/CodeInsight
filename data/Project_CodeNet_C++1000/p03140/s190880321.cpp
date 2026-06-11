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
    ll N;
    string A, B, C;

    cin >> N;
    cin >> A >> B >> C;
    ll cnt = 0;
    rep(i, N) {
        if (A[i] == B[i] && A[i] == C[i]) {
            continue;
        } else if ((A[i] == B[i] && A[i] != C[i]) ||
                   (A[i] == C[i] && A[i] != B[i]) ||
                   (B[i] == C[i] && A[i] != C[i])) {
            cnt += 1;
        } else {
            cnt += 2;
        }
    }

    cout << cnt << endl;

    return 0;
}