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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;
    vector<Vi> is_open(N, Vi(10));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < 10; j++) {
            cin >> is_open[i][j];
        }
    }
    vector<Vl> P(N, Vl(11));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    ll ans = -L_INF;
    for (ll mask = 1; mask < (1LL << 10); mask++) {
        ll score = 0;
        for (ll i = 0; i < N; i++) {
            ll cnt = 0;
            for (ll j = 0; j < 10; j++) {
                if ((mask >> j) & 1 && is_open[i][j]) {
                    ++cnt;
                }
            }
            score += P[i][cnt];
        }
        ans = max(ans, score);
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}