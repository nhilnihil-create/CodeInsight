#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, a;
    cin >> N;
    map<ll,int> c;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        c[a]++;
    }
    ll ans = 0;
    for ( auto it = c.rbegin(); it != c.rend(); it++ ) {
        if ( it->second == 0 ) continue;
        ll s = 1;
        while ( s <= it->first ) s *= 2;
        if ( it->first * 2 == s ) {
            ans += it->second / 2;
            it->second -= (it->second / 2) * 2;
        } else {
            auto it2 = c.find(s - it->first);
            if ( it2 == c.end() || it2->second == 0) continue;
            int n1 = min(it->second, it2->second);
            ans += n1;
            it->second -= n1;
            it2->second -= n1;
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}