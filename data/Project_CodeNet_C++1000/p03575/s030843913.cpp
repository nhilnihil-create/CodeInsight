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

const ll TREE_SIZE = 100100;

class Unionfind {
    public:
        vector<ll> par, siz, rank;
        Unionfind();
        ll root(ll x);
        void merge(ll x, ll y);
        bool issame(ll x, ll y);
        ll size(ll x);
};

int main() {
    ll n, m, ans = 0; cin >> n >> m;
    vector<P> edge(m);
    rep(i, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        edge[i] = make_pair(a, b);
    }
    // 各枝についてやる
    rep(i, m) {
        Unionfind t;
        bool ok = true;
        rep(j, m) {
            if(j == i) continue;
            else {
                t.merge(edge[j].first, edge[j].second);
            }
        }
        rep(j, n-1) {
            frep(k, j+1, n-1) {
                if(!t.issame(j, k)) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) {
            ans++;
        }
    }
    
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

Unionfind::Unionfind() {
    par.resize(TREE_SIZE);
    siz.resize(TREE_SIZE);
    rank.resize(TREE_SIZE);
    rep(i, TREE_SIZE) {
        par[i] = i;
        siz[i] = 1;
        rank[i] = 0;
    }
}
ll Unionfind::root(ll x) {
    if(par[x] == x) return x;
    else {
        return par[x] = root(par[x]);
    }
}
void Unionfind::merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
        par[x] = y;
        siz[y] += siz[x];
    }
    else {
        par[y] = x;
        siz[x] += siz[y];
        if(rank[x] == rank[y]) rank[x]++;
    }
}
bool Unionfind::issame(ll x, ll y) {
    return root(x) == root(y);
}
ll Unionfind::size(ll x) {
    return siz[root(x)];
}