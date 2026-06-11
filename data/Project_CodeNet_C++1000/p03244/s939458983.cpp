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
    ll n;
    cin >> n;
    map<ll, ll> a, b;
    rep(i, n) {
        ll v; cin >> v;
        if((i%2) == 0) {
            if(a.count(v)) a[v]++;
            else a[v] = 1;
        }
        else {
            if(b.count(v)) b[v]++;
            else b[v] = 1;
        }
    }
    vector<P> odd, even; // 個数、数
    for(auto p: a) {
        odd.push_back(make_pair(p.second, p.first));
    }
    for(auto p: b) {
        even.push_back(make_pair(p.second, p.first));
    }
    sort(ALL(odd), greater<P>());
    sort(ALL(even), greater<P>());
    if(odd[0].second != even[0].second) {
        cout << n-odd[0].first-even[0].first << endl;
    }
    else {
        if(odd.size() == 1 && even.size() == 1) {
            cout << n/2 << endl;
        }
        else if(odd.size() == 1) {
            cout << n-odd[0].first-even[1].first << endl;
        }
        else if(even.size() == 1) {
            cout << n-odd[1].first-even[0].first << endl;
        }
        else {
            ll o, e;
            o = n-odd[0].first-even[1].first;
            e = n-odd[1].first-even[0].first;            
            cout << min(o, e) << endl;
        }
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
