#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール


// 処理内容
int main() {
    
    ll k; cin >> k;
    vector<ll> dp(k, INF);
    dp[1] = 1;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push(pair<ll, ll>(dp[1], 1));

    while (!q.empty()) {

        ll c = q.top().first;
        ll v = q.top().second;
        q.pop();

        ll n1 = (v + 1) % k;
        ll n2 =  v * 10 % k;
        if (chmin(dp[n1], dp[v] + 1))
            q.push(pair<ll, ll>(dp[n1], n1));
        if (chmin(dp[n2], dp[v]))
            q.push(pair<ll, ll>(dp[n2], n2));

    }

    cout << dp[0] << endl;
    
}