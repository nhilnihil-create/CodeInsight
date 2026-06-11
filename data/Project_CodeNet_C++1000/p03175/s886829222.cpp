#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
#define mii map<int,int>  
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 1e5+5;
int dp[N][2];
int n;
vi adjList[N];

int dfs(int node,int color,int par){
    if(dp[node][color]!=-1){
        return dp[node][color];
    }
    int ans = 0;
    int sum1 = 1,sum2 = 1;
    if(!color){
        for(auto x:adjList[node]){
            if(x!=par){
                sum1 = (sum1*dfs(x,1,node))%mod;
            }
        }
    }else{
        sum1 = 0;
    }
    for(auto x:adjList[node]){
        if(x!=par){
            sum2 = (sum2*dfs(x,0,node))%mod;
        }
    }
    ans = (sum1+sum2)%mod;
    return dp[node][color] = ans;
}

void solve(){
    cin>>n;   
    loop(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    mset(dp,-1); 
    int ans = (dfs(1,0,-1))%mod;
    cout<<ans<<endl;
}

int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
