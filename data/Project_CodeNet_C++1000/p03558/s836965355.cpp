// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
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
#define pr pair<int,int>
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5 + 10;
bool visit[MAXN][180];
int n;

void dfs(int val,int sum){
    if(sum >= 100) return;
    if(visit[val][sum]) return;
    visit[val][sum] = 1;
    FOR(i,0,9) dfs((10*val + i)%n, sum + i);
}

void solve(){
    cin>>n; 
    FOR(i,0,9) dfs(i%n,i);

    int ans = 1e9;
    FOR(i,1,99) if(visit[0][i]) ans = min(ans,i);
    cout<<ans<<endl;
}

signed main(){

   FastRead;    

    int t = 1; 
    // cin>>t; 
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}