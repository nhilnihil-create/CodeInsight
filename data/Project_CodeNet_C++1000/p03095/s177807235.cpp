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

ll solve(vector<ll> C);

int main() {

    ll N;
    string S;

    cin >> N >> S;

    vector<ll> C(26, 0);

    rep(i, N) {
        C[S[i] -'a']++;
    }

    ll ans;

    ans = solve(C);

    cout << ans;

    return 0;
}

ll solve(vector<ll> C) {
    ll tmp = 1, D = pow(10, 9) + 7;

    rep(i, 26) {
        if (C[i] > 0) {
            tmp *= C[i] + 1;
            if (tmp > D) {
                tmp %= D;
            }
        }
    }
    tmp--;

    return tmp;
}

