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
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
#define CHOKUDAI_ const
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using cll = DANCE_ DANCE_ CHOKUDAI_;
using  ld = long double;
using namespace std;

// モジュール


// 処理内容
int main() {
    
    ll n; cin >> n;

    switch (n) {
        case 3:
            cout << "2 5 63\n";
            return 0;
        case 4:
            cout << "2 5 20 63\n";
            return 0;
    }
    
    vector<ll> ans; ans.reserve(30010);

    ll tmod = n % 2 ? 3 : 0;
    ll gn = min(10000LL, (n+1) / 2);
    if (gn % 2) gn--;
    ll kn = n - gn;
    while (kn % 4 != tmod) {
        gn--;
        kn++;
    }

    for (ll i = 3; kn > 0; kn--, i += 3) {
        ans.push_back(i);
    }
    for (ll i = 2; gn > 0; i += 2) {
        if (i % 3 == 0) continue;
        gn--;
        ans.push_back(i);
    }
    
    sort(ALL_OF(ans));
    REP(i, ans.size()) {
        cout << ans[i] << " \n"[i == i_len-1];
    }

    // cerr << endl;
    // DUMP(n);

    // DUMP(kn);
    // DUMP(gn);
    
    // ll gcdall = accumulate(ALL_OF(ans), ans[0],
    //     [](ll a, ll b) -> ll { return gcd(a, b); });
    // DUMP(gcdall);
    // ll sum = accumulate(ALL_OF(ans), 0LL);
    // DUMP(sum % 6);
    // ll ansmax = ans.back();
    // DUMP(ansmax);
    // if (gcdall != 1 || sum % 6 != 0 || ansmax > 30000) {
    //     cerr << "FAIL!!!" << endl;
    // }

}