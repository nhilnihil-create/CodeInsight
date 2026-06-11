#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        c[i] = a[i] + b[i];
    }
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    rep(i, n) if (~i&1) ans += c[i];
    rep(i, n) ans -= b[i];
    cout << ans << endl;
}