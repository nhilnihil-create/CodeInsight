#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    auto err = []() {
        cout << -1 << "\n";
        return 0;
    };
    if ( A + B - 1 > N ) return err();
    if ( A * B < N ) return err();
    vector<vector<ll>> ans(B, vector<ll>());
    ll x = 1;
    int i;
    for ( i = 0; i < B; i++ ) {
        ans[i].push_back(x);
        x++;
    }
    i = 0;
    while ( x <= N ) {
        while ( ans[i].size() >= A ) i++;
        ans[i].push_back(x);
        x++;
    }

    bool first = true;
    for ( int i = B-1; i >= 0 ; i-- ) {
        for ( auto y : ans[i] ) {
            if ( !first ) cout << " ";
            else first = false;
            cout << y;
        }
    }
    return 0;
}

int main() {
    solve();
    return 0;
}