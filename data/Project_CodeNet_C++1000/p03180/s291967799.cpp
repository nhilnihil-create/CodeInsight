/*
 * zyrch - Rupanshu Yadav
 */
#ifdef CREED 
#include "creed.h"
#else
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <sstream>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif


using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL) 

#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

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
#ifdef CREED
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll INF = 1e18;

ll mod = 1000000007;
inline ll fast_expo(ll base,ll power,ll modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}

ll takemod(ll a, ll mo){
	a %= mo;
	if(a < 0) a+=mo;
	return a;
}

// if mod is prime
ll modinv(ll a, ll mo){
	return takemod(fast_expo(takemod(a,mo), mo-2, mo), mo);
}

//=========================CODE STARTS HERE=============================//

int no(int mask, int n) {
    int ans = (1 << n) - 1;
    for(int i = 0; i < n; ++i) {
	if ((1 << i) & mask) {
	    ans &= ~(1 << i); 
	}
    }
    return ans;
}
int main() {
    fast_cin();
    
    ll n;
    cin >> n;
    vector<vector<ll>> dat(n, vector<ll> (n));
    for (int i= 0; i < n; ++i) {
	for (int j = 0;j < n;++j) {
	    cin >> dat[i][j];
	}
    }
    vl score(1 << n);
    ll sc = 0;
    for (int group = 0; group < (1 << n); ++group) {
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < i; ++j) {
		if (group & (1 << i) && group & (1 << j)) sc += dat[i][j];
	    }
	}
	score[group] = sc;
	sc = 0;
    }
    vl dp(1 << n, -INF);
    dp[0] = 0; 
    int ni=0;
    for (int mask = 0; mask < (1 << n); ++mask) {
	ni = no(mask, n);
	for (int j = ni; j; j = (j - 1) & ni) {
	    //~ debug(j);
	    dp[j|mask] = max(dp[j|mask], dp[mask] + score[j]);
	}
    }
		
    cout << dp[(1 << n) - 1];
    return 0; 
}
