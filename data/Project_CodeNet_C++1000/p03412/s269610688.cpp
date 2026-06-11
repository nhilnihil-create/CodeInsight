#include <bits/stdc++.h>

#define repfrom(i, from, n) for (ll i = (from); i < (n); i++)
#define rep(i, n) repfrom(i, 0, n)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n) - 1; i >= 0; i--)

using namespace std;

using ll = long long;
using p  = pair<ll, ll>;
constexpr ll INF = 1LL << 62;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (auto&& a : A) {
        cin >> a;
    }
    for (auto&& b : B) {
        cin >> b;
    }
    
    ll ans = 0;
    for (ll k = 0; k < 29; k++) {
        ll mask = 1 << k;
        
        vector<ll> b;
        transform(B.begin(), B.end(), back_inserter(b), [mask](ll n) { return n % (mask << 1); });
        sort(b.begin(), b.end());
        
        ll ones = 0;
        for (auto a : A) {
            ll amod = a % (mask << 1);
            auto pt1 = lower_bound(b.begin(), b.end(), mask - amod);
            auto pt2 = lower_bound(b.begin(), b.end(), 2 * mask - amod);
            auto pt3 = lower_bound(b.begin(), b.end(), 3 * mask - amod);
            auto pt4 = lower_bound(b.begin(), b.end(), 4 * mask - amod);
            ones += ll(pt2 - pt1) + ll(pt4 - pt3);
        }
        
        if (ones % 2) {
            ans += mask;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
