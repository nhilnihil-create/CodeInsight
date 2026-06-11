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

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll N, M, tmp;
    string S, T, tmpS;

    cin >> N >> M >> S >> T;

    if (M > N) {
        tmpS = T;
        T = S;
        S = tmpS;
    }

    tmp = min(N, M);
    N = max(N, M);
    M = tmp;

    ll x, y;
    x = gcd(N, M);
    y = lcm(N, M);

    for (int i = 0; i < x; i++) {
        if (S[i * N / x] != T[i * M / x]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << y;

    return 0;
}

ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}