#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<char,int> pci;
typedef vector<pair<int,int>> vpii;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define sciii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sciiii(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scl(a) scanf("%lld",&a)
#define scll(a,b) scanf("%lld %lld",&a,&b)
#define sclll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c
#define scllll(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define print(a) printf("%d ",a)
#define println(a) printf("%d\n",a)
#define ln printf("\n")
#define pb(a) push_back(a)
#define m_p(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define rrep(i,e,s) for(int i=e;i>=s;i--)
#define repv(i,m) for(auto i = m.begin();i != m.end();i++)
#define FileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long INF = 4000000000000000000LL;
/************************************* Chocolate *************************************/
const int mod = 1e9+7;
#define white 0
#define black 1
vvi dp,grp;
void dfs(int node,int par){
    dp[node][white] = dp[node][black] = 1;
    for(int v:grp[node]){
        if(v == par) continue;
        dfs(v,node);
        dp[node][black] = (1LL * dp[node][black] * dp[v][white])%mod;
        dp[node][white] = (1LL * dp[node][white] * (dp[v][white] + dp[v][black])%mod)%mod;
    }
}
int main(){
    int n;
    sci(n);
    grp.resize(n+1);
    dp.resize(n+1,vi(2));
    rep(i,1,n-1){
        int u,v;
        scii(u,v);
        grp[u].pb(v);
        grp[v].pb(u);
    }
    dfs(1,-1);
    cout << (dp[1][white]+dp[1][black])%mod << endl;
}