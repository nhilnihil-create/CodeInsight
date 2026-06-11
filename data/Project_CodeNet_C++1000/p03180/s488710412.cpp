#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
void err(istream_iterator<string> it) {cout << '\n';}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " : ";
    err(++it, args...);
}
 
 
#define F first
#define S second
#define ll long long
#define pb push_back
#define db double
#define ld long double
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define all(x) (x).begin(),(x).end()
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define TEST int T; cin >> T; while(T--)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//#define int long long
 
const int N = 1e5 + 5, inf = 2e9 + 7, mod = 1e9 + 7;
const ll INF = 2e18 + 7, MOD = 1e15 + 7;

int n, a[16][16];
ll pre[1 << 16], dp[1 << 16]; // dp[mask] = max ans if rabbits already taken

bool has(int n, int i) {
    return (n >> i) & 1;
}

void rec(int i, vector<int>& v, ll cur, int mask, int group) {
    if(i == v.size()) {
        dp[mask] = max(dp[mask], cur + pre[group]);
        return;
    }
    rec(i + 1, v, cur, mask ^ (1 << v[i]), group ^ (1 << v[i]));
    rec(i + 1, v, cur, mask, group);
}

signed main() { __
//    freopen("lcm.in", "r", stdin);
//    freopen("lcm.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!has(mask, i)) continue;
            for (int j = i + 1; j < n; j++) {
                if (!has(mask, j)) continue;
                pre[mask] += a[i][j];
            }
        }
    }
//    for (int i = 0; i < (1 << n); i++) dp[i] = -INF;
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if(!has(mask, i)) {
                v.pb(i);
            }
        }
        rec(0, v, dp[mask], mask, 0);
    }
    cout << dp[(1 << n) - 1];
    return 0;
}

