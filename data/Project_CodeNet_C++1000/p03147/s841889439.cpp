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
    Vl H(N);
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }
    ll ans = 0;
    while (true) {
        ll cnt = 0;
        for (ll i = 0; i < N - 1; i++) {
            if (H[i] > 0 && H[i + 1] == 0) ++cnt;
            if (H[i] > 0) --H[i];
        }
        if (H[N - 1] > 0) {
            ++cnt;
            --H[N - 1];
        }

        if (cnt == 0) break;

        ans += cnt;
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