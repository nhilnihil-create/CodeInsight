#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {
    ll N, M, ans;
    cin >> N >> M;

    vector<ll> A(M);
    vector<ll> gap(M - 1);

    rep(i, M) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    ans = A[M - 1] - A[0];

    rep(i, M -1) {
        gap[i] = A[i + 1] - A[i];
    }

    sort(gap.begin(), gap.end(), greater<>());

    rep(i, min(N - 1, M - 1)) {
        ans -= gap[i];
    }

    cout << ans;

    return 0;
}
