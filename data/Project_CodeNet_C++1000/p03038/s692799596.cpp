#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
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
    ll n, m; cin >> n >> m;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];
    sort(ALL(a));
    Vp vp(m);
    rep(i, 0, m) cin >> vp[i].se >> vp[i].fi;
    sort(ALL(vp));
    reverse(ALL(vp));
    // rep(j, 0, n) cout << a[j] << " ";
    // coel;
    ll r = 0;
    rep(i, 0, m){
        // cout << vp[i].fi << "  ";
        ll m = r;
        rep(j, m, min(n, m+vp[i].se)){
            if(a[j]>=vp[i].fi) break;
            a[j] = vp[i].fi;
            r++;
        }
        // rep(j, 0, n) cout << a[j] << " ";
        // coel;
    }
    ll ans = 0;
    rep(i, 0, n) ans += a[i];
    co(ans);
    
    return 0;
}
