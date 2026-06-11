#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb(t) push_back(t)
#define pt(num) cout << num << "\n"
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;


ll N, M;
ll clr[MAX];
vector<ll> g[MAX];

void dfs(ll u, ll c) {
    clr[u]=c;
    
    ll i, v;
    ll f=1;
    for(i=0; i<g[u].size(); i++) {
        v=g[u][i];
        if(clr[v]==-1)
            dfs(v, 1-c);
    }
    
}

int main(void) {
    cin >> N >> M;
    ll i, j;
    
    for(i=0; i<M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    for(i=0; i<N; i++) clr[i]=-1;
    dfs(0, 0);
    
    ll f=1;
    for(i=0; i<N; i++) {
        for(j=0; j<g[i].size(); j++) {
            ll v=g[i][j];
            if(clr[i]==clr[v]) {
                f=0;
                break;
            }
        }
    }
    
    if(!f) pt(N*(N-1)/2-M);
    else {
        ll a=0, b=0;
        for(i=0; i<N; i++) {
            if(clr[i]==0) a++;
            if(clr[i]==1) b++;
        }
        pt(a*b-M);
    }
    
}




