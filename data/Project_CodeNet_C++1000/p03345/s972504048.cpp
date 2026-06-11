#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, (n) - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define REPS(c, s) for (char c : s)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REV(c) reverse(ALL(c))
#define sz(v) (int)v.size()
#define endl '\n'
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline void prn(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << ' ';}
template<class T> inline void printv(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << (i == n - 1 ? endl : ' ');}
template<class T> inline void printvv(vector<vector<T>>& v) {for (auto u : v) printv(u);}
template<class T> inline void printlnv(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << endl;}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
 
void solve();
 
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
    solve();
    return 0;
}

class Combination {
    vector<ll> factorial;
    vector<ll> fact_inverse;
    vector<ll> inverse;
    int mod;

    void init(int size) {
        factorial[0] = 1;
        factorial[1] = 1;
        fact_inverse[0] = 1;
        fact_inverse[1] = 1;
        inverse[1] = 1;

        for (int i = 2; i < size; i++) {
            factorial[i] = factorial[i - 1] * i % mod;
            inverse[i] = mod - inverse[mod % i] * (mod / i) % mod;
            fact_inverse[i] = fact_inverse[i - 1] * inverse[i] % mod;
        }
    }

    public:
        Combination(int size, int m) {
           factorial = vector<ll>(size);
           fact_inverse = vector<ll>(size);
           inverse = vector<ll>(size);
           mod = m;
           init(size);
        }
    
        ll calc(int n, int k) {
            if (n < k) {
                return 0;
            }
            if (n < 0 || k < 0) {
                return 0;
            }
            return factorial[n] * (fact_inverse[k] * fact_inverse[n - k] % mod) % mod;
        }

        // i.e. nHk
        ll with_repetition(int n, int k) {
            return calc(n + k - 1, k);
        }
};

vector<vector<ll>> pascals_triangle(int n) {
    vector<vector<ll>> combi(n + 1, vector<ll>(n + 1));
    REP(i, n + 1) REP(j, i + 1) {
        if (j == 0 || j == i) combi[i][j] = 1LL;
        else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }
    return combi;
}

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << (k % 2 == 0 ? a - b : b - a) << endl;
}
