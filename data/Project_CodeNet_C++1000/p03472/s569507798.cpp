#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////


int main() {
    ll n, h; cin >> n >> h;
    Vl a(n), b(n);
    ll a_mx = 0;
    rep(i, 0, n) cin >> a[i] >> b[i], chmax(a_mx, a[i]);
    ll sumb = 0;
    ll ans = 0;
    Vl vb;
    rep(i, 0, n){
        if(b[i] > a_mx) vb.push_back(b[i]);
    } 
    sort(ALL(vb), greater<ll>());
    rep(i, 0, sz(vb)){
        h -= vb[i]; ans++;
        if(h <= 0){
            co(ans);
            return 0;
        }
    }
    ans += ((h+a_mx-1)/a_mx);
    co(ans);

    return 0;
}
