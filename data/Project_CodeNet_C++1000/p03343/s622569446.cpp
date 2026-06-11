#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ld> id;

#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define ROF(i, a, b) for(int i=(a); i>=(b); i--)
#define MEM(x, v) memset(x, v, sizeof(x))
#define FILL(x, n, v) fill(x, x+n, v);
#define ALL(x) x.begin(), x.end()
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define f first
#define s second
#define ins insert
#define e emplace
#define eb emplace_back
#define ef emplace_front
#define p push
#define pf push_front
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define ft front
#define bk back
#define pp pop
#define ppb pop_back
#define ppf pop_front

#define db cout<<"YEET\n";
#define ct(x) cout<<x<<'\n';

const ll MOD = 1e9+7; //998244353
const ll MAXN = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);

int main(){
    FAST
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> values;
    set<ll> sorted;
    values.pb(0);
    FOR(i,1,n){
        ll x;
        cin >> x;
        values.eb(x);
        sorted.ins(x);
    }

    ll ans = INF;
    for (auto limit : sorted){
        vector<ll> newvec, fin;
        FOR(i,1,n){
            if (values[i] < limit){
                sort(ALL(newvec));
                ll sz = (ll)(newvec.size())-k;
                FOR(j,0,sz) fin.pb(newvec[j]);
                newvec.clear();
            } else newvec.pb(values[i]);
        }

        sort(ALL(newvec));
        ll sz = (ll)(newvec.size())-k;
        FOR(i,0,sz) fin.pb(newvec[i]);

        if (fin.size() >= q) {
            sort(ALL(fin));
            ll diff = fin[q-1] - fin[0];
            ans = min(ans, diff);
        }
    }
    cout << ans;
}