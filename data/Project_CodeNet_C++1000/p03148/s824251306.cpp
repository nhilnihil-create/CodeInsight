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
    vector<Pll> sushis(N);
    for (ll i = 0; i < N; i++) {
        cin >> sushis[i].second >> sushis[i].first;
    }
    sort(sushis.begin(), sushis.end(), greater<Pll>());
    ll pdeli = 0;
    stack<ll> dups;
    unordered_set<ll> st;
    for (ll i = 0; i < K; i++) {
        ll t, d;
        tie(d, t) = sushis[i];
        if (st.find(t) != st.end()) {
            dups.emplace(d);
        }
        pdeli += d;
        st.emplace(t);
    }

    ll nk = (ll)st.size();
    ll ans = pdeli + nk * nk;

    for (ll i = K; i < N; i++) {
        ll t, d;
        tie(d, t) = sushis[i];
        if (st.find(t) != st.end()) continue;
        if (dups.empty()) break;
        pdeli -= dups.top();
        dups.pop();
        pdeli += d;
        st.emplace(t);
        nk = (ll)st.size();
        ans = max(ans, pdeli + nk * nk);
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