#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 100005;

ll dp[sze][2];
vi adj[sze];

void dfs(int start,int par){
    if(adj[start].size()==0){
        dp[start][0]=1;
        dp[start][1]=1;
        return;
    }
    ll a=1,b=1;
    for(auto x:adj[start]){
        if(par==x) continue;
        dfs(x,start);
        a=(a*(dp[x][0]+dp[x][1])%mod)%mod;
        b=(b*(dp[x][0])%mod)%mod;
    }
    dp[start][0]=a;
    dp[start][1]=b;
}

void solve() {
    int n;
    cin>>n;
    int m=n-1;
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    cout<<(dp[0][0]+dp[0][1])%mod<<endl;
}

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
        mem(dp);
       solve();
    }

  return 0;
}