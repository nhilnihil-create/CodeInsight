#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define cps CLOCKS_PER_SEC
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
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
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { int operator()(int x) const { return x ^ RANDOM; }};
// cc_hash_table<int, int, hash<int>> cnt;

const int MAXN = 2e5 + 10;
int p[MAXN];
map<int,int> positions;
bool visit[MAXN];

void solve(){
    int n; cin>>n;
    FOR(i,1,n) {
        cin>>p[i]; positions[p[i]] = i;
    }

    int siz = 0;
    FOR(i,1,n){
        if(visit[i]) continue;
        int idx = i;
        int pos = positions[idx];
        int t_siz = 1;
        visit[idx] = 1;
        while(positions[idx+1] > pos){
            pos = positions[idx+1];
            idx++; t_siz++;
            visit[idx] = 1;
        }
        
        siz = max(siz,t_siz);
    }

    cout<<n-siz<<endl;
}
 
signed main(){
 
    FastRead; 

 
    int t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<":\n";
        solve();
    }
}
 