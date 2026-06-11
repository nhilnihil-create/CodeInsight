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
    ll N, K;
    cin >> N >> K;
    Vl V(N);
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }

    ll ans = 0;
    Vl negas;
    for (ll l = 0; l <= min(N, K); l++) {
        for (ll r = 0; l + r <= min(N, K); r++) {
            ll score = 0;
            negas.clear();
            for (ll i = 0; i < l; i++) {
                score += V[i];
                if (V[i] < 0) {
                    negas.emplace_back(V[i]);
                }
            }
            for (ll i = 0; i < r; i++) {
                score += V[N - 1 - i];
                if (V[N - 1 - i] < 0) {
                    negas.emplace_back(V[N - 1 - i]);
                }
            }

            sort(negas.begin(), negas.end());

            for (ll i = 0; i < min(K - (l + r), (ll)negas.size()); i++) {
                score -= negas[i];
            }

            ans = max(ans, score);
        }
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