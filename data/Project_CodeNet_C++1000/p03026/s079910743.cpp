#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 998244353
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
const int mod = 1e9 + 7;

vvl G(10005);
vl ans(10005);
bool visit[10005];
vl c(10005,INF);

void dfs(ll u){
    visit[u] = true;
    ans[u] = c.back();
    c.pop_back();
    for(auto v : G[u]){
        if(visit[v]) continue;
        dfs(v);
    }
}

int main(){
    ll n; cin >> n;
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    c.resize(n,0);
    rep(i,n) cin >> c[i];
    sort(all(c));
    ll sum = 0;
    rep(i,n-1){
        sum += c[i];
    }
    dfs(0);
    cout << sum << endl;
    rep(i,n) cout << ans[i] << " ";
}
