#include<bits/stdc++.h>

#define ll  long long int
#define ld  long double
#define MAX 1000001
#define MOD 1000000007
#define pi  3.14159265358979323846264338
#define mp  make_pair
#define pb  push_back
#define pll pair<ll,ll>
#define vl  vector<ll>
#define vi  vector<int>
#define vs  vector<string>
#define vc  vector<char>
#define fst first
#define sec second
#define foi(i, a, b)   for(ll i = a; i<b;i++)
#define fod(i, a, b)   for(ll i = a;i>=b;i--)
#define all(v)         (v).begin(), (v).end()
#define max3(a, b, c)  max(max(a,b), c)
#define min3(a, b, c)  min(min(a,b), c)
#define ump  unordered_map<ll,ll>
#define us   unordered_set<ll>
#define nl  "\n"
#define INF  (ll)1e18
#define s(v) (ll)(v).size()
#define e(v) (v).empty

using namespace std;

ll gcd(ll a,ll b) { if (a==0) return b; return gcd(b%a,a);}

ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = (power(x, y/2)%MOD); 
    if (y%2 == 0) 
        return ((temp)*(temp))%MOD; 
    else
        return ((x)*(temp)*(temp))%MOD; 
}

void dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& dp,int i){
    visited[i] = 1;
    
    for(int child : adj[i]){
        if(!visited[child]){
            dfs(adj,visited,dp,child);
        }
        dp[i] = max(dp[i],1 + dp[child]);
    }

}

void solve(){   
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    int x,y;

    foi(i,0,m){
        cin>>x>>y;
        adj[x].pb(y);
    }
    vector<int> dp(n+1,0);
    vector<int> visited(n+1,0);
    foi(i,1,n+1){
        if(!visited[i]){
            //cout<<i<<"\n";
            dfs(adj,visited,dp,i);
        }
    }
    int ans = 0;
    foi(i,0,n+1){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";

}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}