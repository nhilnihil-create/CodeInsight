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
    ll n, sum = 0; cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> c(n), ans(n);
    
    rep(i, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, n) cin >> c[i];
    sort(ALL(c));
    rep(i, n-1) sum += c[i];

    queue<ll> que;
    vector<bool> used(n, false);
    que.push(0);
    used[0] = true;
    ans[0] = c[n-1];

    ll num = 1;
    while(!que.empty()) {
        ll t = que.front();
        que.pop();

        rep(i, g[t].size()) {
            ll next = g[t][i];
            if(!used[next]) {
                que.push(next);
                used[next] = true;
                ans[next] = c[n-1-num];
                num++;
            }
        }
    }

    cout << sum << endl;
    rep(i, n) cout << ans[i] << " ";
    cout << endl;

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
