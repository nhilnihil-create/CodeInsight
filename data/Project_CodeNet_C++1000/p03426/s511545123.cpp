#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, D;
    cin >> H >> W >> D;
    ll m = 0;
    map<ll, pll> ma;
    rep(i, H) {
        rep(j, W) {
            ll a;
            cin >> a;
            ma[a] = {i, j};
            m = max(m, a);
        }
    }

    vector<ll> table(m + 1, 0);
    for (int i = 0; i < m + 1; i++) {
        if (table[i] != 0)
            continue;
        for (int j = i + D; j < m + 1; j += D) {
            pll a = ma[j], b = ma[j - D];
            table[j] = table[j - D] + abs(a.first - b.first) +
                       abs(a.second - b.second);
        }
    }

    int Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
        cout << table[R[i]] - table[L[i]] << endl;
    }
}