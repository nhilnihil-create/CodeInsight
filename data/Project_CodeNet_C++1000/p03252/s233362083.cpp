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
    string s, t;
    cin >> s >> t;
    bool ok = true;
    vector<vector<ll>> sames(26), samet(26);
    rep(i, t.size()) {
        sames[t[i]-'a'].push_back(i);
        samet[s[i]-'a'].push_back(i);
    }
    rep(i, 26) {
        if(sames[i].size() <= 1) continue;
        bool tmp = true;
        char a = s[sames[i][0]];
        rep(j, sames[i].size()) {
            if(a != s[sames[i][j]]) tmp = false;
        }
        if(!tmp) ok = false;
    }
    rep(i, 26) {
        if(samet[i].size() <= 1) continue;
        bool tmp = true;
        char a = t[samet[i][0]];
        rep(j, samet[i].size()) {
            if(a != t[samet[i][j]]) tmp = false;
        }
        if(!tmp) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

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
