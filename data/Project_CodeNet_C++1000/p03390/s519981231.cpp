#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

ll sqrtll(ll N) {
    ll ok = 1;
    ll ng = sqrt(N) + 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid <= N) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

void solve(ll A, ll B) {
    if (A > B) {
        swap(A, B);
    }

    if (abs(A - B) > 1) {
        ll C = sqrt(A * B);
        if (C * C == A * B) {
            C--;
        }
        if (C * (C + 1) >= A * B) {
            cout << 2 * C - 2 << endl;
        } else {
            cout << 2 * C - 1 << endl;
        }
    } else {
        cout << 2 * A - 2 << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q;
    vector<p> qs;
    for (ll q = 0; q < Q; q++) {
        ll A, B;
        cin >> A >> B;
        qs.emplace_back(A, B);
    }

    for (auto&& q : qs) {
        solve(q.first, q.second);
    }
    return 0;
}

