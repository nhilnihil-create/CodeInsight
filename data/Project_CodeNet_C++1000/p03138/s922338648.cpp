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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; ll k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];
    ll x = 0;
    bool leading_zero = true;
    bool less = false;
    for (int i = 39; i >= 0; --i) {
        if (k>>i&1) leading_zero = false;
        if (!leading_zero) {
            if (less || k>>i&1) {
                int cnt1 = 0;
                rep(j, n) if (a[j]>>i&1) cnt1++;
                if (cnt1 >= (n+1)/2) {
                    less = true;
                } else {
                    x |= 1LL<<i;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, n) ans += x ^ a[i];
    cout << ans << endl;
}