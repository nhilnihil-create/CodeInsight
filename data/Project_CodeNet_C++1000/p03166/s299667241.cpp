/*
    quid-pro-quo: LOGIC for AC
    written by: codercell07
    LANG: C++ 11
    Problem: random
*/
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define testcases freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define ui unsigned int
#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sz(x) (int)x.size()
#define pq priority_queue /*maxim at top(max-heap)*/
#define pqmax priority_queue<int, vector<int>, greater<int>> /*minim at top(min-heap)*/
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define asc(x) sort(all(x))
#define desc(x) sort(all(x), greater<int>())
#define time_el (double)time/CLOCKS_PER_SEC
using namespace std;
const int MAX=2e6; //dummy, make sure change as per constraints
const ll M=1e9+7, inf=1e18;
const char nl='\n';
 
ll apbmc(ll a, ll b, ll c){ a%=c; ll res=1; while(b){ if(b&1) res=res*a%c; a=a*a%c; b>>=1; } return res;}
ll apb(ll x, ll y){ ll temp; if(y==0) return 1;  temp=apb(x, y/2); if(y%2==0) return temp*temp;  else return temp*temp*x;}
 

void dfs(vi &dist, int i, vvi &adj){
    if(dist[i]!=-1) return;
    dist[i]=0;
    for(int u: adj[i]){
        dfs(dist, u, adj);
        dist[i]=max(dist[i], dist[u]+1);
    }
}

void solve(){   
    //clock_t time;
    int n, m; cin>>n>>m;
    vvi adj(n, vi());
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        --x, --y;
        adj[x].pb(y);
    }
    vi dist(n, -1);
    for(int i=0; i<n; i++){
        dfs(dist, i, adj);
    }
    cout<<*max_element(all(dist));
}
int main(){
    fastio;
    // #ifndef ONLINE_JUDGE
    //     testcases;
    // #endif // !DEBUG
    cout<<fixed<<setprecision(10);
    
    //int t; cin>>t; while(t--) solve();    
    solve();

    return 0;
}
//points to check:
//  * check for constraints, mainly array!
//  * EDGE CASES
//  * check for integer overflow, use long long!
//  * learn, do, solve, share something, NOW!