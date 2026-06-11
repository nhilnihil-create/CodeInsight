#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;




int main() {
    ll N, tmp;
    cin >> N;
    vector<ll> F(N);
    vector<vector<ll>> P(N, vector<ll>(11));
    rep(i,N) rep(j,10) {
        cin >> tmp;
        if (j == 0) F.at(i) = tmp;
        else {
            F.at(i) *= 2;
            F.at(i) += tmp;
        }
    }
    rep(i,N) rep(j,11) cin >> P.at(i).at(j);
    ll ans = -10e10;
    for (ll bit = 1; bit < (1<<10); ++bit) {
        ll profit = 0;
        for (int i = 0; i < N; ++i) {
            int cnt = __builtin_popcount(bit & F.at(i));
            profit += P.at(i).at(cnt);
        }
        ans = max(ans, profit);
    }
    cout << ans << endl;
}

