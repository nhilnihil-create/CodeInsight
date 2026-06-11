#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ttgl, null_type,less<ttgl>, rb_tree_tag,tree_order_statistics_node_update>*/
 
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 100001;
ll arr[mxN];
map<ll, int> mp;
int sz[mxN];
vector<ttgl> ans;
vector<int> adj[mxN];
int par[mxN];
int n;
int dist[mxN];
ll sd = 0;
bool istree() {
    memset(dist, -1, sizeof(dist));
    queue<int> Q;
    Q.push(mp[arr[0]]);
    dist[mp[arr[0]]] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int v: adj[u]) {
            if(dist[v]!=-1) {
              return false;
            }
            Q.push(v);
            dist[v] = dist[u]+1;
        }
    }   
    owo(i, 0, n) {
        if(dist[i]==-1) {
            return false;
        }
        sd+=dist[i];
    }
    if(sd!=arr[0])return false;
    return true;
}
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    owo(i, 0, n) {
        cin>>arr[i];
        mp[arr[i]] = i;
    }
    sort(arr, arr+n);
    uwu(i, n, 1) {
        int u = mp[arr[i]];
        sz[u]++;
        ll k = arr[i] + 2LL*sz[u] - n;
        if(mp.count(k)) {
            int v = mp[k];
            par[u] = v;
            adj[v].senpai(u);
            ans.senpai({u, v});
            sz[v]+=sz[u];
        }else {
            cout<<"-1\n";
            exit(0);
        }
    }
    if(istree()) {
        for(auto p: ans) {
            cout<<(p.first+1)<<" "<<(p.second+1)<<"\n";
        }
    }else {
        cout<<"-1\n";
    }
    return 0;
}