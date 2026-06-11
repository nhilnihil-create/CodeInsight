#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
 
#define init ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define setpr(x) cout << setprecision((x))
#define PI atan(1)*4
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mk(a , b) { min((a) , (b)) , max((a) , (b)) }
#define flush cout.flush()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endc "\n"
#define MOD 998244353
#define meme(x) memset((x), 0, sizeof((x)))
#define memo(x) memset((x),-1, sizeof((x)))
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

// #define int ll

ll egcd(ll a, ll b, ll &x, ll &y){
    if (a == 0LL){  
        x = 0LL;  
        y = 1LL;  
        return b;  
    }
    ll xx, yy;
    ll val = egcd(b % a, a, xx, yy);  
    x = yy - (b / a) * xx;  
    y = xx;  
    return val;
}

ll gcd(ll a, ll b){
    while(true){
        if(a>b)
            swap(a,b);
        if (a == 0) 
            return b; 
        ll p = b % a  , q = a;
        a = p;
        b = q;
    }
}
 
ll powerMod(ll x,ll y){
    ll res = 1;
    x %= MOD;
    while(y > 0){
        if(y & 1)res = (res*x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return res%MOD;
}

//  ==========     //\\       //||     ||====//||
//      ||        //  \\        ||     ||   // ||
//      ||       //====\\       ||     ||  //  ||
//      ||      //      \\      ||     || //   ||
//  ========== //        \\  ========  ||//====|| 
//  code

void solve(){
    int n,i,j,k,l,p;
    cin >> n;
    vector<int> dp(n, 0), h(n);
    for(auto &i : h){
        cin >> i;
    }

    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + abs(h[i - 1] - h[i]);
        if(i >= 2){
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }

    cout << dp[n - 1] << endc;
}

int32_t main(){
    init;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
