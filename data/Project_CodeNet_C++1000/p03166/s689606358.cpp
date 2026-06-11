#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i < (n); ++i)
#define repD(i, a, n) for(ll i = a; i > (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (long long) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
// #define mp make_pair
#define pb push_back
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<double> vd;
typedef vector<pii> vii;
long long Ceil(long long a, long long b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll p=1000000007;
float E = 0.00000000000001;
ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        ll q=power(x,y/2);
        q=q%p;
        return (q*q)%p;
    }
    ll q=power(x,y/2);
    q=q%p;
    return ((x%p)*((q*q)%p))%p; 
}
bool isPowerOfTwo (long long x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}  

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a); 
}
long long int mod(long long int a, long long int b) {
    long long int ret = a%b; return ret>=0? ret: ret+b; 
}
void dfs_visit(int i, vector<int> adj[], vector<int> &visited, vector <int> &vec){
    // dbg(i);
    if(visited[i])
        return;
    visited[i] = 1;
    for(auto x:adj[i])
        dfs_visit(x, adj, visited, vec);
    vec.push_back(i);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector <int> adj[n], radj[n];
        for(int i = 0 ; i < m ; i++){
            int x,y;cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            radj[y].push_back(x);
        }
        vector <int> visited(n, 0);
        vector <int> vec;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
                dfs_visit(i, adj, visited, vec);
        }
        // for(auto &x:vec)
            // x += 1;
        // dbg(vec);
        vector <int> dp(n, 0);
        int ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            int node = vec[i];
            for(auto x:radj[node])
                dp[node] = max(dp[node], 1+dp[x]);
            ans = max(ans, dp[node]);
        }
        // dbg(dp);
        cout<<ans<<endl;
    }
    return 0;
}
