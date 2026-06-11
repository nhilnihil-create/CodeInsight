#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll n; cin >> n;
    vector<ll> c(n-1), s(n-1), f(n-1);
    rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
    rep(j, n) {
        ll now = 0;
        Rep(i, j, n-1) {
            if(now < s[i]) now = s[i];
            else if(now % f[i] != 0) now = (now + f[i]) / f[i] * f[i];
            now += c[i];
        }
        cout << now << endl;
    }
}