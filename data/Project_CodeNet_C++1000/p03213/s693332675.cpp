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
    ll n, ans = 0;
    cin >> n;
    map<ll, ll> m;
    ll a=0, b1=0, b2=0, c1=0, c2=0, d1=0, d2=0;
    frep(i, 2, n) {
        ll tmp = i;
        frep(j, 2, tmp) {
            if((tmp%j) == 0) {
                while((tmp%j) == 0) {
                    if(m.count(j)) m[j]++;
                    else m[j] = 1;
                    tmp /= j;
                }
            }
        }
    }
    for(auto p: m) {
        auto v = p.second;
        if(v >= 74) a++;

        if(2 <= v && v <= 23) b1++;
        else if(24 <= v) b2++;

        if(4 <= v && v <= 13) c1++;
        else if(14 <= v) c2++;

        if(2 <= v && v <= 3) d1++;
        else if(4 <= v) d2++;
    }
    ans += (a + b1*b2 + b2*(b2-1) + c1*c2 + c2*(c2-1) + \
            d1*d2*(d2-1)/2 + d2*(d2-1)*(d2-2)/2);
    cout << ans << endl;
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
