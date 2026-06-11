#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 0
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

// ある範囲の中央値を求める→ソートか二分探索がよい
// 今回の範囲のパターン数→ N(N-1)/2 あるので
//   - 各範囲の中央値を求める
//   - 中央値の集合から中央値を求める
// の順で行うと TLE する
//
// 値 x が中央値の中央値（問題の答え）になるかどうかを
// 一気に判定することを考える
//
// x が中央値の中央値になりえるかどうかは、
// 「x がある範囲の総パターンのうち半数以上で x が中央値である」
// ことで成り立つ
//
// これは a の各値を x 以上を 1, x 未満を -1 とした数列に変換し、
// [0, i] までの累積和で表した数列( S とする)の転倒数によって判定可能
// ある範囲[l, r]の総和は Sr - S(l-1) で表すことができ、
// ここが 0 以上なら「 x は範囲 [l, r] で中央値になりえる」といえる
// つまり Sr >= S(l-1) ならその範囲において x は中央値になり得、
// この [r, l] の全パターンの大小比較は、転倒数を求める作業と同様の
// 処理で O(N log N) で行うことができる
//
// よって、ある範囲の総パターンにおいて x が中央値になりえるかを O(N log N)、
// x の値が答えかどうかを O(log aiの最大 = 10^9) で求められるため、
// O(N log N log 10^9) で答えが求まる

#if 0
// 1-indexed であることに注意
template<typename T>
class BITree {
    public:
        BITree(int n) : m_N(n + 1) { m_Tree.assign(m_N, 0); }
        // [1, i] の合計値を返す (log m_N)
        // 閉区間であることに注意
        T Sum(int i) {
            if(i < 1 || i >= m_N) { return 0; }
            T s = 0;
            while(i > 0) { s += m_Tree[i]; i -= i & -i; }
            return s;
        }
        // [i, j] の合計値を返す (log m_N)
        // i < j
        // 閉区間であることに注意
        T Sum(int i, int j) {
            if(i > j) { return 0; }
            return Sum(j) - Sum(i-1);
        }
        // i 番目の要素(1-indexed)に x を足して更新 O(log m_N)
        void Add(int i, T x){ while(i < m_N) { m_Tree[i] += x; i += i & -i; } }
    private:
        int m_N;            // 要素数
        vector<T> m_Tree;   // BIT 本体
};
#else
template <class Abel> struct BITree {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;

    /* [1, n] */
    BITree(int n) : dat(n + 1, UNITY_SUM) { }
    void Init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void Add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel Sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel Sum(int a, int b) {
        return Sum(b) - Sum(a - 1);
    }

    /* debug */
    void Print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << Sum(i, i + 1) << ",";
        cout << endl;
    }
};
#endif

// 数列 p の順番を維持したままペアを全パターンとったとき、左の数字 <= 右の数字 のペア数
// 数列の各要素は 1 以上でなければならない
static inline ll GetInversionCnt4(const vector<ll>& p) {
    ll ret = 0;
#if 1
    ll max_val = 100005;
    ll min_val = -100005;
    //for(auto& val : p) {
    //    max_val = max(max_val, val);
    //    min_val = min(min_val, val);
    //}
    // 負の数を扱えるようオフセットを設定
    ll min_offset = (min_val < 0) ? abs(min_val) + 1 : 0;
    BITree<ll> bit(max_val + min_offset + 10);    // 以左に現れた数を BIT で管理
#else
    ll min_offset = 100005;
    BITree<ll> bit(200010);    // 以左に現れた数を BIT で管理
#endif
    for(int i = 0; i < p.size(); ++i) {
        ret += bit.Sum(1, p[i] + min_offset);  // 自分以下のものを数える
        bit.Add(p[i] + min_offset, 1);   // 現れた数を更新
    }
    return ret;
}

ll N;
vector<ll> A, A2, S;

// x が中央値の中央値になりえるかどうか
static inline bool Check(ll x) {
    ll cnt = 0;

    // A の各要素について x 以上なら 1, x 未満なら -1 の配列を作成
    REP(i, N) {
        if(A[i] < x) { A2[i] = -1; }
        else { A2[i] = 1; }

        // A2 の累積和配列 S を作成
        if(i == 0) { S[i] = A2[i]; }
        else { S[i] = S[i-1] + A2[i]; }

        if(S[i] >= 0) { cnt++; }
    }

    // Sr >= Sl の範囲の数が全体の半分以上なら x は中央値になり得る
    cnt += GetInversionCnt4(S);
    ll all_pat = N * (N + 1) / 2;

    return (cnt >= (all_pat / 2));
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    ll lb = LLINF, ub = -LLINF;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
        lb = min(lb, A[i]);
        ub = max(ub, A[i]);
    }

    if(N == 1) {
        printf("%lld\n", A[0]);
        return 0;
    }

    A2.resize(N);
    S.resize(N);

    while(ub - lb > 1) {
        ll x = (lb + ub) / 2;
        if(Check(x)) { lb = x; }
        else { ub = x; }
    }

    printf("%lld\n", Check(ub) ? ub : lb);

    return 0;
}
