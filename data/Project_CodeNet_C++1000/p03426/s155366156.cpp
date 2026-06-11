#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll h, w, d; cin >> h >> w >> d;
    vector<vector<ll>> sum(d);
    map<ll, P> m;
    rep(i, h) {
        rep(j, w) {
            ll a; cin >> a;
            m[a] = make_pair(i, j);
        }
    }
    rep(i, d) {
        ll n = i+1, s = 0;
        sum[i].push_back(s);
        while(n <= h*w) {
            ll x, y, nx, ny; // 前のx,y 次のx,y
            x = m[n].first;
            y = m[n].second;
            nx = m[n+d].first;
            ny = m[n+d].second;
            ll dist = my_abs(x-nx) + my_abs(y-ny);
            s += dist;
            sum[i].push_back(s); // 累積
            n += d;
        }
    }

    ll q; cin >> q;
    rep(i, q) {
        ll l, r; cin >> l >> r;
        ll a = (l%d); // mod
        // どのvectorを使うか
        if(a == 0) a = d-1;
        else a = a-1;
        ll ans = sum[a][(r-a-1)/d] - sum[a][(l-a-1)/d];
        cout << ans << endl;
    }
    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
