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

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    vector<ll> ab;
    rep(i, x) {
        rep(j, y) ab.push_back(a[i]+b[j]);
    }
    sort(ALL(ab), greater<ll>());
    sort(ALL(c), greater<ll>());
    
    vector<ll> abc;
    rep(i, min(k, x*y)) {
        rep(j, min(k, z)) {
            abc.push_back(ab[i]+c[j]);
        }
    }
    sort(ALL(abc), greater<ll>());
    rep(i, k) cout << abc[i] << endl;
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
        ret %= MOD;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count))%MOD;
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

