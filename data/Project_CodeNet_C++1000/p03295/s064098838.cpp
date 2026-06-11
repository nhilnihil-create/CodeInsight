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

    ll N, M;
    cin >> N >> M;
    vector<Pii> dems(M);
    for (ll i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        dems[i] = make_pair(a, b);
    }
    sort(dems.begin(), dems.end());

    ll ans = 0;
    ll rmn = dems[0].second;
    for (ll i = 1; i < M; i++) {
        ll l, r;
        tie(l, r) = dems[i];
        if (l >= rmn) {
            ++ans;
            rmn = r;
        }
        else {
            rmn = min(rmn, r);
        }
    }

    ++ans;

    cout << ans << endl;

    return 0;
}