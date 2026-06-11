#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (B > D) {
        cout << "No\n";
    } else {
        if (A < B) {
            cout << "No\n";
        } else {
            if (A % B > C) {
                cout << "No\n";
            } else {
                if (B - gcd(B, D) > C) cout << "No\n";
                else cout << "Yes\n";
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    REP(i, T) solve();
    return 0;
}
