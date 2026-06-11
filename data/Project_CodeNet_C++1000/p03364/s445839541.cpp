#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> S[i];
    }
    vector<string> t(N);
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            t[i].push_back(S[j][i]);
        }
    }
    for ( int i = 0; i < N; i++ ) {
        S[i].append(S[i]);
    }
    ll cnt = 0;
    for ( int k = 0; k < N; k++ ) {
        bool ok = true;
        for ( int i = 0; i < N; i++ ) {
            if ( t[(i+k)%N] != S[i].substr(k, N) ) {
                ok = false;
                break;
            }
        }
        if ( ok ) cnt++;
    }
    ll ans = cnt * N;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}