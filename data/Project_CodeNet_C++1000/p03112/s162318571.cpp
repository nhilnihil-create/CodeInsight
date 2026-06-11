#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    set<ll> s, t;
    rep(i, a){
        ll x;
        cin >> x;
        s.insert(x);
    }
    rep(i, b){
        ll x;
        cin >> x;
        t.insert(x);
    }
    s.insert(-1001001001001001);
    s.insert(1001001001001001);
    t.insert(-1001001001001001);
    t.insert(1001001001001001);
    rep(i, q){
        ll x;
        cin >> x;
        auto it = s.upper_bound(x);
        it--;
        ll ls = *it;
        it = t.upper_bound(x);
        it--;
        ll lt = *it;
        ll rs = *s.lower_bound(x);
        ll rt = *t.lower_bound(x);
        ll ans = 0;
        ans = min({
            max(x - ls, x - lt),
            max(rs - x, rt - x),
            min(rt + x - 2 * ls, 2 * rt - x - ls),
            min(rs + x - 2 * lt, 2 * rs - x - lt)
        });
        cout << ans << endl;
    }
    
}