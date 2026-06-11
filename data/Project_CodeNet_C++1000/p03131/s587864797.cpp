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
    ll count = 0;

    ll K, A, B, ans = 0;
    cin >> K >> A >> B;

    if (B <= A + 2 || K - A < 1) {
        ans = K + 1;
    }
    else {
        ans += B + (K - A - 1) / 2 * (B - A) + (K - A - 1) % 2;
    }
    cout << ans;

    return 0;
}
