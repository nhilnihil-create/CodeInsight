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
#define MOD 1000000007
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

//  ==========      //\\       //||     ||====//||
//      ||         //  \\        ||     ||   // ||
//      ||        //====\\       ||     ||  //  ||
//      ||       //      \\      ||     || //   ||
//  ==========  //        \\  ========  ||//====|| 
//  code

vector<int> a;
const int N = 1e5 + 2, M = 101;
int dp[M][N];

void solve(){
    int n,i,j,k,l,p;
    meme(dp);
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a)
        cin >> i;
    
    for(i = 0; i <= a[0]; i++)
        dp[0][i] = 1;

    vector<int> prev(N, 0);
    prev[0] = 1;

    for(i = 1; i <= k; i++){
        prev[i] = dp[0][i] + prev[i - 1];
        prev[i] %= MOD;
    }

    // for(i = 0; i <= k; i++)
    //     cout << prev[i] << " - ";
    // cout << endc;

    for(i = 1; i < n; i++){
        for(j = 0; j <= k; j++){
            dp[i][j] = prev[j];
            if(j > a[i])
                dp[i][j] -= prev[j - a[i] - 1];
            dp[i][j] = (dp[i][j] + MOD) % MOD;
            // cout << dp[i][j] << " ";
        }
        // cout << endc;
        prev[0] = dp[i][0];
        for(j = 1; j <= k; j++){
            prev[j] = dp[i][j] + prev[j - 1];
            prev[j] %= MOD;
        }
        // for(j = 0; j <= k; j++)
        //     cout << prev[j] << " - ";
        // cout << endc;
    }

    cout << dp[n - 1][k] << endc;
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
