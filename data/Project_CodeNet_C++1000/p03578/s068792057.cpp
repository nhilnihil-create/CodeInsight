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
    map<ll, ll> d;
    rep(i, n) {
        ll a; cin >> a;
        d[a]++;
    }
    ll m; cin >> m;
    rep(i, m) {
        ll a; cin >> a;
        if(!d.count(a) || d[a] <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        d[a]--;
    }
    cout << "YES" << endl;
}