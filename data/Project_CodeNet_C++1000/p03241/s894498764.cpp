
// Problem : D - Partition
// Contest : AtCoder - AtCoder Beginner Contest 112
// URL : https://atcoder.jp/contests/abc112/tasks/abc112_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

/* DEBUGGING */
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
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

/* MACROS */ 
typedef long long int ll;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef map<int,int> mii;

#define  ff          first
#define  ss          second
#define  pb          push_back
#define  IOS         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  lb          lower_bound
#define  ub          upper_bound
#define  all(x)      (x).begin(), (x).end()
#define  ps(x,y)     fixed<<setprecision(y)<<x
#define  setbit(x)   __builtin_popcountll(x)
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
#define  repr(i,a,b) for(int i=a ; i>=b ; --i)

/* CONSTANTS */ 
#define PI 3.141592653589793
const ll MOD = 1e9 + 7;
const ll INF = 1000000000;
const ll MAX_N = 2e5 + 2;

// #define cerr if(false)cerr
/* CODE STARTS HERE */

void solve(){
    ll n,m; cin >> n >> m;
    vll divs(0);
    
    for(ll i=1;i*i<=m;++i){
        if(m%i==0){
            divs.pb(i);
            
            if(m/i != i) divs.pb(m/i);
        }
    }
    
    sort(all(divs) , greater<ll>());
    int sz = divs.size();
    
    rep(i,0,sz){
        ll temp = n*divs[i];
        
        if(temp <= m) {cout << divs[i]; return;}
    }    
}

int main(){
    IOS;
    solve();
}