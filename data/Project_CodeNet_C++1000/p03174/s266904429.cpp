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
#define deb(x)		cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int N = 22;
int dp[1 << N];
int adj[N][N];
int n;
inline void relax(int & a , int b){
    a = (a % MOD + b % MOD) % MOD;
}
int fun(int mask){
    auto & res = dp[mask];
    if(res != -1)
        return dp[mask];
    int ans = 0;
    int man = __builtin_popcount(mask);
    if(man == n)
        return res = 1;
    for(int i = 0 ; i < n ; i++)
        if(adj[man][i] && !((mask >> i) & 1))
            relax(ans , fun(mask | (1 << i)));
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    memset(dp , -1 , sizeof dp);
    fo(i , n)
        fo(j , n)
            cin >> adj[i][j];

    cout << fun(0) <<  '\n';
    
    

    return 0;

}

