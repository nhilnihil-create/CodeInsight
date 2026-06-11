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
const ll N = 3001;

double dp[N][N];

ll n,m;
vector<double> v;

double solve(ll i, ll cur){
	if(i<0) return 1;
	if(dp[i][cur]!=-1) return dp[i][cur];
	double x=0;
	if(cur<m-1)
		x = v[i]*solve(i-1,cur+1);
	double y = (1-v[i])*solve(i-1,cur);
	dp[i][cur] = x+y;
	return dp[i][cur];
}

int main()
{
    auto start_time = Clock;
    FASTIO

    #ifndef JD
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    rep(i,N)rep(j,N) dp[i][j]=-1;

	cin>>n;
	m = (n+1)/2;
	v.resize(n);
	rep(i,n) {
		cin>>v[i];
		v[i] = 1-v[i];
	}
	cout<<fixed<<setprecision(10)<<solve(n-1,0);
    



    auto end_time = Clock;
    #ifndef TIME
    	return 0;
    #endif
	cout << "\nTime elapsed: "
	<< (double)duration_cast<milliseconds>(end_time-start_time).count() 
	<< "ms";


    return 0;
}
