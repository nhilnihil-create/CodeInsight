#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

ll lcm(ll a, ll b)
{
    if (a < b) {
        ll t = a;
        a = b;
        b = t;
    }
    ll aa = a;
    ll bb = b;
    ll r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    ll gcd = b;
    a = aa;
    b = bb;
    return a * b / gcd;
}

int main(int argc, char **argv)
{
    ll N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    ll L = lcm(N, M);
    map<ll, char> X;
    REP(i, N) {
        X.insert(make_pair((L / N) * i, S[i]));
    }
    bool f = true;
    REP(i, M) {
        if (X.find((L / M) * i) != X.end()) {
            if (X[(L / M) * i] != T[i]) {
                f = false;
                break;
            }
        }
    }
    if (f) cout << L << endl;
    else cout << -1 << endl;

    return 0;
}
