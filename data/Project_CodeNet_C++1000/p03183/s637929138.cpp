#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const ll MAXN = 1e3 + 10;
ll w[MAXN],s[MAXN],v[MAXN];
ll indexs[MAXN];

bool cmp(ll a,ll b){
    if(w[a] + s[a] == w[b] + s[b]) return v[a] < v[b];
    else return (w[a] + s[a] < w[b] + s[b]);
}

ll n;
ll dp[MAXN][20004];

ll rec(ll idx,ll t_w){
    if(idx == n+1) return 0;

    ll &ans = dp[idx][t_w];

    if(ans != -1) return ans;

    ans = rec(idx+1,t_w);

    if(s[indexs[idx]] >= t_w) ans = max(ans,v[indexs[idx]] + rec(idx+1,t_w + w[indexs[idx]]));
    return ans;
}

void solve(){
    cin>>n;

    FOR(i,1,n){
        cin>>w[i]>>s[i]>>v[i];
        indexs[i] = i;
    }

    sort(indexs+1,indexs+n+1,cmp);

    MINUS(dp);

    cout<<rec(1,0)<<endl;
}

signed main(){
 
   FastRead;    

    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}