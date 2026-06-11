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
// vector<vector<T>> のラッパクラス (プァ～)
// pの余りを取りたくない場合3箇所のコメントアウトを解除すること
template<typename T = long long>
class matrix {
    vector<vector<T>> value;
public:
    T get(const size_t i) const { return this->rows() == 1 ? this->get(0, i) : this->get(i, 0); }
    T get(const size_t i, const size_t j) const { return this->value.at(i).at(j); }
    inline size_t rows() const { return this->value.size(); }
    inline size_t cols() const { return this->value.empty() ? 0 : this->value[0].size(); }
    matrix() : value() {}
    matrix(const matrix &a) : value(a.value) {}
    matrix(size_t n, size_t m = 0) : value(n, vector<T>(m ? m : n, 0)) {}
    matrix(initializer_list<initializer_list<T>> init) : value() {
        const size_t n = init.size();
        const size_t m = [&]() {
            size_t maxm = 0;
            for (const auto& initi : init) {
                const size_t mi = initi.size();
                if (mi > maxm) maxm = mi;
            }
            return maxm;
        }();
        this->value = vector<vector<T>>(n, vector<T>(m, 0));
        size_t i = 0, j;
        for (const auto &initi : init) {
            for (const auto &v : initi) {
                this->value[i][j++] = v;
            }
            i++; j = 0;
        }
    }
    // ラムダ式の引数は(size_t, size_t)、返り値はTとすること (まあ整数型なら大丈夫でしょ)
    template <class LAMBDA>
    static matrix<T> map(const size_t n, const size_t m, LAMBDA f) {
        matrix<T> r(n, m);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                r.value[i][j] = f(i, j);
            }
        }
        return r;
    }
    static matrix eye(const size_t n) {
        matrix<T> r(n);
        for (size_t i = 0; i < n; i++) r.value[i][i] = 1;
        return r;
    }
    matrix<T> operator+ (const matrix<T> &a) {
        if (this->rows() != a.rows()) exit(EXIT_FAILURE);
        if (this->cols() != a.cols()) exit(EXIT_FAILURE);
        const size_t n = this->rows();
        const size_t m = this->cols();
        return matrix<T>::map(n, m, [&](size_t i, size_t j) {
            // return this->value[i][j] + a.value[i][j];
            return (this->value[i][j] + a.value[i][j]) % p;
        });
    }
    matrix<T> operator- (const matrix<T> &a) {
        if (this->rows() != a.rows()) exit(EXIT_FAILURE);
        if (this->cols() != a.cols()) exit(EXIT_FAILURE);
        const size_t n = this->rows();
        const size_t m = this->cols();
        return matrix<T>::map(n, m, [&](size_t i, size_t j) {
            // return this->value[i][j] - a.value[i][j];
            return (this->value[i][j] + p - a.value[i][j]) % p;
        });
    }
    matrix<T> operator* (const matrix<T> &a) {
        if (this->cols() != a.rows()) exit(EXIT_FAILURE);
        const size_t n = this->rows();
        const size_t m = this->cols();
        const size_t q = a.cols();
        return matrix<T>::map(n, q, [&](size_t i, size_t j) {
            T term = 0;
            for (size_t k = 0; k < m; k++)
                // term += this->value[i][k] * a.value[k][j];
                (term += this->value[i][k] * a.value[k][j]) %= p;
            return term;
        });
    }
    matrix<T>& operator+= (const matrix<T> &a) {
        matrix<T> r = *this + a;
        this->value.swap(r.value);
        return *this;
    }
    matrix<T>& operator-= (const matrix<T> &a) {
        matrix<T> r = *this - a;
        this->value.swap(r.value);
        return *this;
    }
    matrix<T>& operator*= (const matrix<T> &a) {
        matrix<T> r = *this * a;
        this->value.swap(r.value);
        return *this;
    }
    matrix<T> transpose() {
        const size_t n = this->rows();
        const size_t m = this->cols();
        return matrix<T>::map(m, n, [&](size_t i, size_t j) {
            return this->value[j][i];
        });
    }
    matrix<T> pow(long long int n) {
        if (n == 0) {
            return matrix<T>::idtm(n);
        } else if (n == 1) {
            return *this;
        } else {
            matrix temp = this->pow(n / 2);
            return n % 2 == 0 ? temp * temp : temp * temp * *this;
        }
    }
};
template <typename T>
inline void DUMPMTR(const matrix<T> &m) {
    for (size_t i = 0; i < m.rows(); i++)
        for (size_t j = 0; j < m.cols(); j++)
            cerr << m.get(i, j) << " \n"[j==3];
}

// 処理内容
int main() {
    
    map<char, matrix<ll>> lmap;
    lmap['A'] = matrix<ll>({
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1}
    });
    lmap['B'] = matrix<ll>({
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });
    lmap['C'] = matrix<ll>({
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });
    lmap['?'] = lmap['A'] + lmap['B'] + lmap['C'];
    
    matrix<ll> x0 = {{0, 0, 0, 1}};
    matrix<ll> a = matrix<ll>::eye(4);

    string s; cin >> s;
    REP(i, s.size()) {
        a *= lmap[s[i]];
    }
    matrix<ll> x = x0 * a;
    cout << x.get(2) << endl;
    
}