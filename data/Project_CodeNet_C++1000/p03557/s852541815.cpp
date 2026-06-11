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

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    Vl a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));

    Vl B(n);
    rep(i, 0, n){
        B[i] = c.end() - upper_bound(ALL(c), b[i]);
    }
    for(int i = n-1-1; i >= 0; i--){
        B[i] += B[i+1];
    }
    ll ans = 0;
    rep(i, 0, n){
        auto it = upper_bound(ALL(b), a[i]);
        ans += B[it - b.begin()];
    }
    co(ans);

    return 0;
}
