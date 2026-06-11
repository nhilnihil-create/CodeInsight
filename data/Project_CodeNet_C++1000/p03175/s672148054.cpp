//P : Independent Set (Atcoder)
#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int N = 1e5 + 100;
vi adj[N];
ll dp[N][2];
void dfs(int src = 0 ,int par = 0){
    dp[src][0] = dp[src][1] = 1;
    for(int i : adj[src]){
        if(i == par) continue;
        dfs(i , src);
        dp[src][1] *= (dp[i][0] % MOD);
        dp[src][0] *= (dp[i][1] + dp[i][0]) % MOD;
        dp[src][1] %= MOD;
        dp[src][0] %= MOD;
    }
    
    return ;
}

signed main(){

#ifndef ONLINE_JUDGE
	//freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    
    fo(i , n - 1){
        int u , v;
        cin >> u >> v;
        u--;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    
    dfs();

    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';


    return 0;

}

