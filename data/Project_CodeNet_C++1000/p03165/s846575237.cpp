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


int main()
{
    auto start_time = Clock;
    FASTIO

    #ifndef JD
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

	
    string s,t,ans="";
    cin>>s>>t;
    ll n=t.size(),m=s.size();
    vector<vll> dp(n+1,vll(m+1,0));
    vector<vector<pll>> par(n+1,vector<pll>(m+1,{0,0}));

    for(ll i=1;i<=n;++i){
    	for(ll j=1;j<=m;++j){
    		if(chmax(dp[i][j],dp[i-1][j])){
    			par[i][j] = {i-1,j};
    		}
    		if(chmax(dp[i][j],dp[i][j-1])){
    			par[i][j] = {i,j-1};
    		}
    		if(s[j-1]==t[i-1]){
    			if(chmax(dp[i][j],dp[i-1][j-1]+1)){
    				par[i][j] = {i-1,j-1};
    			}
    		}
    	}
    }
    
    ll i=n,j=m;
    while(i&&j){
    	ll x=i,y=j;
    	tie(i,j) = par[i][j];
    	if(dp[i][j]==dp[x][y]) continue;
    	ans.pb(t[x-1]);
    }
    reverse(all(ans));
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
