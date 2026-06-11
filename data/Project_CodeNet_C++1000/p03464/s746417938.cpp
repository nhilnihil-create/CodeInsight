#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n;
//     cin >> n;
//     vll a(n);
//     rep(i, n) cin >> a[i];
//     vll l(n+1), r(n+1);
//     l[n] = 2;
//     r[n] = 2;
//     for (int i = n-1; i >= 0; --i) {
//         ll mn = (l[i+1] + a[i] - 1) / a[i] * a[i];
//         ll mx = r[i+1] / a[i] * a[i];
//         if (!(mn <= mx)) {
//             cout << -1 << endl;
//             return 0;
//         }
//         l[i] = mn;
//         r[i] = mx + a[i] - 1;
//     }
//     cout << l[0] << " " << r[0] << endl;
// }

int main() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    
    auto f = [&](ll x) {
        for (int i = 0; i < n; ++i) {
            x = x - x%a[i];
        }
        return x;
    };
    ll mn, mx;
    ll sm = accumulate(all(a), 0LL);
    ll l = 0, r = 2 + sm;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        if (f(m) >= 2) r = m;
        else l = m; 
    }
    mn = r;
    l = 0, r = 2 + sm;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        if (f(m) <= 2) l = m;
        else r = m;
    }
    mx = l;
    if (mn > mx) cout << -1 << endl;
    else cout << mn << " " << mx << endl;
}