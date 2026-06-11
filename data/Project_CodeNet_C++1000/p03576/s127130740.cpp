#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rnfor(i,a,b) for(ll (i) = (a) - 1; (i) >= (b); --(i))
#define ll long long
#define mod (1000000007)
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
const ll inf = 1e9;

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n)t *= i;
    return t;
}

ll combinations(ll n, ll k) {
    ll r = 1;
    rep1(i, k)r = r * n-- / i;
    return r;
}

int main(){
    ll k,n;
    cin >> n >> k;
    vector<ll> x(n),y(n);
    rep0(i, n)cin >> x[i] >> y[i];
    ll ans = 4 * 1e18 + 1;
    rep0(xl, n)rep0(xr, n)rep0(yl, n)rep0(yr, n){
        ll lx = xl,rx = xr,ly = yl,ry = yr;
        if(x[lx] > x[rx])swap(lx, rx);
        if(y[ly] > y[ry])swap(ly, ry);
        ll cnt = 0;
        rep0(i, n)if(x[i] >= x[lx] && x[i] <= x[rx] && y[i] >= y[ly] && y[i] <= y[ry])++cnt;
        if(cnt >= k)ans = min(ans, (x[rx] - x[lx]) * (y[ry] - y[ly]));
    }
    pf(ans);
    return 0;
}
