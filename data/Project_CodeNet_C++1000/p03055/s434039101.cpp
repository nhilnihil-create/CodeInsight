#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 200001;
int memo[mxN][2];
int solve(int a, int turn) {
    if(memo[a][turn]!=-1)return memo[a][turn];
    if(turn==0) {
        //takahashi's turn
        if(a==1)return 1;
        if(a==0||a==2)return 0;
        //cout<<solve(a-1, turn^1)<<" "<<solve(a-2)
        return memo[a][turn] = solve(a-1, turn^1)|solve(a-2, turn^1);
    }else {
        //aoki's turn
        if(a==0||a==2)return 1;
        if(a==1)return 0;
        return memo[a][turn] = solve(a-1, turn^1)&solve(a-2, turn^1);
    }
}
int n;
vector<int> adj[mxN];
int dist[mxN];
void dfs(int u, int p=-1) {
    for(int v:adj[u]) {
        if(v^p) {
            dist[v] = dist[u]+1;
            dfs(v, u);
        }
    }
}
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    memset(memo, -1, sizeof(memo));
    int a, b;
    owo(i, 0, n-1) {
        cin>>a>>b;
        a--; b--;
        adj[a].senpai(b);
        adj[b].senpai(a);
    }
    int first = -1;
    dfs(0);
    int mx = 0;
    owo(i, 0, n) {
        if(dist[i]>mx) {
            mx = dist[i];
            first = i;
        }
    }
    dist[first] = 0;
    dfs(first);
    owo(i, 0, n) {
        if(dist[i]>mx) {
            mx = dist[i];
        }
    }
    //cout<<mx<<"\n";
    cout<<(solve(mx+1, 0) ? "First\n" : "Second\n");
    return 0;
}