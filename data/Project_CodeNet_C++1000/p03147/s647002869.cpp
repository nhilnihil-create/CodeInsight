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
ll LCM(ll x, ll y);

int main() {
    ll N, MAX = 0, k, ans = 0, t, tmp;
    cin >> N;

    vector<ll>A(N);

    rep(i, N) {
        cin >> A[i];
        if (MAX < A[i]) {
            MAX = A[i];
            k = i;
        }
    }

    t = 0;
    while (A[k] != 0) {
        tmp = 0;
        t = 2;
        rep(i, N) {
            if (A[i] > 0) {
                A[i] --;
                if (t == 2) {
                    tmp++;
                    t = 1;
                }
            }
            else {
                if (t == 1) {
                    t = 2;
                }
            }
        }
        ans += tmp;
    }

    cout << ans;

    return 0;
}
