#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;


int main(){FIN

    ll a,b,q;cin>>a>>b>>q;
    set<ll> s, t;
    s.insert(1e18);
    s.insert(-1e18);
    t.insert(1e18);
    t.insert(-1e18);

    REP(i,a){
        ll sa; cin>>sa;
        s.insert(sa);
    }
    REP(i,b){
        ll tb; cin>>tb;  
        t.insert(tb);
    }


    REP(i, q){
        ll x; cin>>x;
        ll rs = *s.lower_bound(x);
        ll rt = *t.lower_bound(x);
        auto it = s.lower_bound(x);
        it--;
        ll ls = *it;
        it = t.lower_bound(x);
        it--;
        ll lt = *it;
        ll ans = min({
            max(x-ls, x-lt),
            max(rs-x, rt-x),
            min(rt-ls+x-ls, rt-x+rt-ls),
            min(rs + x - 2 * lt, 2 * rs - x - lt)
        });
        cout<<ans<<endl;
    }

    return 0;
}