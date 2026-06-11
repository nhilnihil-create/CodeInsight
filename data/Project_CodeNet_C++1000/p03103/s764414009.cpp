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
    ll N, M;
    cin >> N >> M;
    vector<Pll> items(N);
    for (ll i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end());
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (M > items[i].second) {
            ans += items[i].first * items[i].second;
            M -= items[i].second;
        }
        else {
            ans += items[i].first * M;
            break;
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