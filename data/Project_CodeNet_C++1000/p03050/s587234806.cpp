#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

vector<ll> enum_div(ll n) {
    vector<ll> result;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            result.push_back(i);
            if (i*i != n) {
                result.push_back(n/i);
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vll div = enum_div(n);
    ll ans = 0;
    rep(i, div.size()) {
        ll m = div[i]-1;
        if (m == 0) continue;
        if (n / m == n % m) ans += m;
    }
    cout << ans << endl;
}