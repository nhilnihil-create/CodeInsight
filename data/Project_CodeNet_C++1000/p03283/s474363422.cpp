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
    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<Vl> vnum(N + 1, Vl(N + 1));
    for (ll i = 0; i < M; i++) {
        ll l, r;
        cin >> l >> r;
        --l, --r;
        ++vnum[0][r];
        --vnum[l + 1][r];
        --vnum[0][N];
        ++vnum[l + 1][N];
    }

    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j < N; j++) {
            vnum[i][j + 1] += vnum[i][j];
        }
    }

    for (ll j = 0; j <= N; j++) {
        for (ll i = 0; i < N; i++) {
            vnum[i + 1][j] += vnum[i][j];
        }
    }

    for (ll i = 0; i < Q; i++) {
        ll p, q;
        cin >> p >> q;
        --p, --q;
        cout << vnum[p][q] << "\n";
    }
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
