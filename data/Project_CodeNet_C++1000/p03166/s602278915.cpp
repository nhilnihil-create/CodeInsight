#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define odd(x) ((x)&1)
#define even(x) (!odd(x))
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(auto i=0;i<n;++i)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST_CASE int tc;cin>>tc;while(tc--)
#define Clock high_resolution_clock::now()

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define JD
// #define TIME

/******************************************************************************************************************************/


const ll inf = 2e18;
const ll mod = 1e9+7;
const ll N = 1e5+3;

vector<vll> adj;
vll dp,vis;
ll ans=0;

void solve(ll x){
	vis[x]=1;
	bool f=0;
	for(auto i:adj[x]){
		if(dp[i]==-1) solve(i);
		chmax(dp[x],dp[i]+1);
		f=1;
	}
	if(!f) dp[x]=0;
}

int main()
{
    auto start_time = Clock;
    FASTIO

    #ifndef JD
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

	
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
   	dp.resize(n+1,-1),vis.resize(n+1,0);

    rep(i,m){
    	ll x,y; cin>>x>>y;
    	adj[y].pb(x);
    }

    rep(i,n){
    	if(!vis[i+1]){
    		solve(i+1);
    	}
    	chmax(ans,dp[i+1]);
    }

    cout<<ans;



    auto end_time = Clock;
    #ifndef TIME
    	return 0;
    #endif
	cout << "\nTime elapsed: "
	<< (double)duration_cast<milliseconds>(end_time-start_time).count() 
	<< "ms";


    return 0;
}
