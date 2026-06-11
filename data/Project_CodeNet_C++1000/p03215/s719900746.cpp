#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    vector<ll> ca(N+1);
    for ( int i = 0; i < N; i++ ) {
        ca[i+1] = ca[i] + A[i];
    }
    vector<ll> s;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i; j < N; j++ ) {
            s.push_back(ca[j+1]-ca[i]);
        }
    }
    ll ans = 0;
    sort(s.rbegin(), s.rend());
    vector<bool> ng(s.size());
    for ( int b = 50; b >= 0; b-- ) {
        int c = 0, v = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            if ( ng[i] ) continue;
            if ( (s[i] >> b) & 1 ) c++;
            if ( c >= K ) {
                v = 1;
                break;
            }
        }
        if ( v == 1 ) {
            ans |= (1LL << b);
            for ( int i = 0; i < s.size(); i++ ) {
                if ( ng[i] ) continue;
                if ( ((s[i] >> b) & 1) == 0 ) {
                    ng[i] = true;
                }
            }
        }

    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}