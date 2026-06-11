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
#define SORT(x) sort((x).begin(), (x).end())
#define CMPSORT(x, cp) sort((x).begin(), (x).end(), cp)
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

ll ft[MAXN];

void upd(ll x, ll val){
    for (; x<=MAXN; x+=x&(-x)) ft[x]+=val, ft[x]%MOD;
    return;
}

ll query(ll x){
    ll res=0;
    for (; x; x-=x&(-x)) res+=ft[x], res%=MOD;
    return res;
}

int main(){
    FAST
    ll n;
    cin >> n;
    ll prev=0;

    vector<ll> groups;
    FOR(i,1,n){
        ll x;
        cin >> x;
        if (x!=prev) groups.pb(x);
        prev=x;
    }
    
    n = groups.size();

    vector<ii> colour;
    ll c[MAXN];
    MEM(c,-1);
    FOR(i,0,n-1){
        ll x = groups[i];
        if (c[x]==-1){
            c[x]=i;
        } else {
            colour.eb(c[x]+1,i+1);
            c[x]=i;
        }
    }
    SORT(colour);

    ll ans=0;
    for (auto pr : colour){
        ll k = query(pr.f) + 1;
        ans+=k;
        ans%=MOD;
        upd(pr.s,k);
    }
    ans++;
    cout << ans%MOD;
}