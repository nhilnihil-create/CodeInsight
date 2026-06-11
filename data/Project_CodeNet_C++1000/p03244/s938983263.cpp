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
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<ll, ll> mp0, mp1;
    for (ll i = 0; i < N; i++) {
        if ((i & 1) == 0) {
            ++mp0[A[i]];
        }
        else {
            ++mp1[A[i]];
        }
    }

    vector<Pll> v0, v1;
    for (const auto& p : mp0) {
        v0.emplace_back(p.second, p.first);
    }
    for (const auto& p : mp1) {
        v1.emplace_back(p.second, p.first);
    }
    sort(v0.begin(), v0.end(), greater<Pll>());
    sort(v1.begin(), v1.end(), greater<Pll>());

    ll ans = L_INF;
    if (v0[0].second != v1[0].second) {
        ans = N - v0[0].first - v1[0].first;
    }
    else if (v0.size() >= 2 && v1.size() >= 2) {
        ans = N - max(v0[0].first + v1[1].first, v0[1].first + v1[0].first);
    }
    else if (v0.size() >= 2) {
        ans = N - max(v0[0].first, v0[1].first + v1[1].first);
    }
    else if (v1.size() >= 2) {
        ans = N - max(v0[0].first + v1[1].first, v1[0].first);
    }
    else {
        ans = N / 2;
    }

    cout << ans << endl;
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