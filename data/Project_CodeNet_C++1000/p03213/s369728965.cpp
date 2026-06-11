#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<ll, ll> factors;
    for (ll i = 2; i <= N; i++) {
        ll y = i;
        for (ll x = 2; x * x <= N; x++) {
            while (y % x == 0) {
                ++factors[x];
                y /= x;
            }
        }
        if (y > 1) {
            ++factors[y];
        }
    }

    vector<Pll> fv;
    for (const auto& p : factors) {
        fv.emplace_back(p);
    }
    ll nf = (ll)fv.size();

    ll ans = 0;

    // 75
    for (ll i = 0; i < nf; i++) {
        if (fv[i].second >= 74) {
            ++ans;
        }
    }

    // 3 * 25
    // 5 * 15
    for (ll i = 0; i < nf; i++) {
        for (ll j = 0; j < nf; j++) {
            if (i == j) continue;
            if (fv[i].second >= 2 && fv[j].second >= 24) {
                ++ans;
            }
            if (fv[i].second >= 4 && fv[j].second >= 14) {
                ++ans;
            }
        }
    }

    // 3 * 5 * 5
    for (ll i = 0; i < nf; i++) {
        for (ll j = 0; j < nf; j++) {
            if (i == j) continue;
            for (ll k = j + 1; k < nf; k++) {
                if (i == k) continue;
                if (fv[i].second >= 2 && fv[j].second >= 4 && fv[k].second >= 4) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}