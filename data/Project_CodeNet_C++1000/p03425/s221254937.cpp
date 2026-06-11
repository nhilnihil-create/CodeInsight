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

    ll N;
    cin >> N;

    vector<ll> X(5);
    string S;

    rep(i, 5) {
        X[i] = 0;
    }


    rep(i, N) {
        cin >> S;
        if (S[0] == 'M') {
            X[0]++;
        }
        if (S[0] == 'A') {
            X[1]++;
        }
        if (S[0] == 'R') {
            X[2]++;
        }
        if (S[0] == 'C') {
            X[3]++;
        }
        if (S[0] == 'H') {
            X[4]++;
        }
    }

    ll ans = 0;

    repl(i, 0, 3) {
        repl(j, i + 1, 4) {
            repl(k, j + 1, 5) {
                ans += X[i] * X[j] * X[k];
            }
        }
    }

    cout << ans;

    return 0;
}