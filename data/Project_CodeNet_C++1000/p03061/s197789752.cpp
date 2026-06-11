#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;

//Segment Tree
//reference materials: <https://www.creativ.xyz/segment-tree-abstraction-979/>, <https://algo-logic.info/segment-tree/>
template <class Monoid>
class SegTree {
    using F = function<Monoid(Monoid,Monoid)>;
    int n;// 葉の数
    vector<Monoid> data; // データを格納する配列
    Monoid def;          // 初期値かつ単位元
    F operation; // 区間クエリ関数
    F update;    // 点更新関数
    // 区間[a,b)の総和。ノードk=[l,r)に着目
    Monoid _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            Monoid c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            Monoid c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }
 
  public:
    // _n:SegTreeのサイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:点更新関数
    SegTree(size_t _n, Monoid _def, F _operation, F _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<Monoid>(2 * n - 1, def);
    }
 
    // 場所i(0-indexed)の値をxで更新
    void set(int i, Monoid x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
 
    // 半開区間[a, b)の区間クエリ
    Monoid query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
 
    // 添字アクセス
    Monoid operator[](int i) {
        return data[i + n - 1];
    }
    // 半開区間[a,b)でx以下の要素を持つ最右位置を返す(二分探索)
    int find_rightest(int a, int b, Monoid x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    // 半開区間[a,b)でx以下の要素を持つ最左位置を返す(二分探索)
    int find_leftest(int a, int b, Monoid x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    int find_rightest_sub(int a, int b, Monoid x, int k, int l, int r) {
        if (data[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    int find_leftest_sub(int a, int b, Monoid x, int k, int l, int r) {
        if (data[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};

typedef pair<double,double> P;

signed main(){
    int n; cin >> n;
    auto GCD = [](int x, int y){return __gcd(x,y); };
    auto upd = [](int x, int y){return y; };
    SegTree<int> ST(n, 0, GCD, upd);
    REP(i,n){
        int a; cin >> a;
        ST.set(i,a);
    }
    int ans = 0;
    REP(i,n) chmax(ans,GCD(ST.query(0,i),ST.query(i+1,n)));
    cout << ans << endl;
}