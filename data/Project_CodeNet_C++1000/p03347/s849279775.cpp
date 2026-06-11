#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
// #define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
 
/*--------------------------------------------------------------------------------
 
--------------------------------------------------------------------------------*/


int main() {
    ll n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];
    ll now = 0;
    ll ans = 0;
    repr(i, 0, n){
        // -1
        if(i > 0 && a[i-1]+1 < a[i]){
            co(-1);
            return 0;
        }
        if(a[i] > i){
            co(-1);
            return 0;
        }
        //
        if(now < a[i]){
            ans += a[i];
            now = a[i];
        }
        // cout << i << " : " << now << endl;
        if(now) now--;
    }
    co(ans);

    return 0;
}