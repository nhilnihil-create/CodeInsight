#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<ll, ll>
#define debug(var) cerr << "[" << #var << "] " << var << '\n'
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;
const ll INFll = 1E+18;
const int MAXN = 100005;

ll par[MAXN];
ll child[MAXN];
vector<int> to[MAXN];
ll dist[MAXN];

void dfs(int v, int p=-1) {
    for (int e: to[v]) {
        if (e==p) continue;
        dist[e] = dist[v] + 1;
        dfs(e, v);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<P> d(n);
    rep(i, n) {
        cin >> d[i].fi;
        d[i].se = i;
    }
    sort(whole(d));

    rrep(i, n) {
        if (i==0) continue;
        ll x = d[i].fi - n+2 + child[i]*2;
        if (x==d[i].fi) {
            pr(-1);
            return 0;
        }
        //debug(d[i].fi);
        //debug(x);
        auto it = lower_bound(whole(d), P(x, 0));
        if (it==d.end() || it->fi!=x) {
            pr(-1);
            return 0;
        }
        par[i] = it-d.begin();
        child[par[i]] += child[i]+1; 
        to[i].pb(par[i]);
        to[par[i]].pb(i);
    }
    ll sum = 0;
    dfs(0, -1);
    rep(i, n) {
        sum += dist[i];
    }
    if (sum!=d[0].fi) {
        pr(-1);
        return 0;
    }

    rep(i, n) {
        if (i==0) continue;
        ll u = d[i].se + 1;
        ll v = d[par[i]].se + 1;
        cout << u << " " << v << "\n";
    }
    return 0;
}
