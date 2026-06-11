//e4-e5-f4
//#include <boost/multiprecision/cpp_int.hpp> 
#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"
//#include "ext/pb_ds/tree_policy.hpp"
typedef long long int ll;
typedef double db;
// __int128 s128;
// __uint128_t u128;
typedef unsigned long long u64;
#define int long long int
#define PI 3.14159265359
#define sz(a) (ll)a.size()
#define lt(a) (ll)a.length()
#define pll pair<ll,ll>
#define tc(x) ll x; cin>>x; while(x--)
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define bac(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define print(a)  for (auto x : a) cout << x << " "; cout << endl
#define sl set<ll>
#define usl unordered_set<ll>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define vl vector<ll>
#define vpl vector<pll>
#define vvl vector<vector<ll>>
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define setbits(a) __builtin_popcountll(a)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define F first
#define S second
#define teevra_gati ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define P 1000000007
#define Q 1000000006
#define inf 1e18
#define N 200005
#define M 105
//using namespace boost::multiprecision; 
//using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(all(v), rng);

ll n, sgt[4*N], dp[N];

void build(ll v, ll s, ll e) {
    if(s>e) return;
    if (s==e) {sgt[v] = dp[s]; return;}
    ll mid = (s+e)/2;
    build(2*v, s, mid);
    build(2*v+1, mid+1, e);
    sgt[v] = max(sgt[2*v],sgt[2*v+1]);
}

ll query(ll v, ll s, ll e, ll qs, ll qe) {
    if(qs>e || qe<s) return 0;
    if(qs<=s && qe>=e) return sgt[v];
    ll mid = (s+e)/2;
    ll left_ans = query(2*v,s,mid,qs,qe), right_ans = query(2*v+1,mid+1,e,qs,qe);
    return max(left_ans,right_ans);
}

void update(ll v, ll s, ll e, ll i, ll val){
    if(i<s || i>e) return;
    if(s==e) {sgt[v] = val; return;}
    ll mid = (s+e)/2;
    update(2*v,s,mid,i,val);
    update(2*v+1,mid+1,e,i,val);
    sgt[v] = max(sgt[2*v],sgt[2*v+1]);
}
void solve(){
    ll n;
    cin>>n;
    vl h(n+1), b(n+1);
    f(i,1,n+1) cin>>h[i];
    f(i,1,n+1) cin>>b[i];
    build(1,1,N);
    f(i,1,n+1){
        dp[h[i]] = b[i] + query(1,1,N,1,h[i]-1); // max: 1...(h[i]-1)
        update(1,1,N,h[i],dp[h[i]]);
    }

    ll ans = query(1,1,N,1,N); // max: 1...N
    cout<<ans;
}

signed main() {
    teevra_gati
        
    solve();

    return 0;
}