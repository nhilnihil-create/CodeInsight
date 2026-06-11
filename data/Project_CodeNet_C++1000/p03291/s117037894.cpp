// May this submission get accepted!

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
constexpr ll p = 1000000007LL;
// 行列累乗; 1e9+7で割ったあまりを求めたい場合は適宜コメントアウトを解除

// 単位行列; idtm<型>(大きさ)
template<typename T>
vector<vector<T>> idtm(const size_t n) {
    vector<vector<T>> r(n, vector<T>(n, 0));
    REP(i, n) r[i][i] = 1;
    return r;
}

// 行列の積
template<typename T>
vector<vector<T>> mltm(const vector<vector<T>> &a, const vector<vector<T>> &b) {
    ull m = a.size(), q = b.size(), r = b[0].size();
    vector<vector<T>> c(m, vector<T>(r, (T)0));
    REP(i, m) REP(j, r) {
        REP(k, m) {
            // c[i][j] += a[i][k] * b[k][j];
            c[i][j] += a[i][k] * b[k][j] % p; c[i][j] %= p;
        }
    }
    return c;
}

// 行列の累乗
template<typename T>
vector<vector<T>> powm(const vector<vector<T>> &a, const ll n) {
    if (n == 0) {
        return idtm<T>(a.size());
    } else if (n == 1) {
        return a;
    } else if (n % 2 == 0) {
        vector<vector<T>> t = powm(a, n/2);
        return mltm(t, t);
    } else {
        vector<vector<T>> t = powm(a, n/2);
        return mltm(mltm(t, t), a);
    }
}

// 処理内容
int main() {

    string s; cin >> s;
    
    vector<vector<ll>> x0 = {
        {0},
        {0},
        {0},
        {1}
    };
    vector<vector<ll>> a_a = {
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    vector<vector<ll>> a_b = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    vector<vector<ll>> a_c = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
        
    };
    vector<vector<ll>> a_any = {
        {3, 0, 0, 1},
        {1, 3, 0, 0},
        {0, 1, 3, 0},
        {0, 0, 0, 3}
    };

    vector<vector<ll>> a = idtm<ll>(4);
    REP(i, s.size()) {
        switch(s[i]) {
            case '?':
                a = mltm(a_any, a);
                break;
            case 'A':
                a = mltm(a_a, a);
                break;
            case 'B':
                a = mltm(a_b, a);
                break;
            case 'C':
                a = mltm(a_c, a);
                break;
        }
    }
    vector<vector<ll>> x = mltm(a, x0);
    cout << x[2][0] << endl;
    
}