#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

template < class T >
class SegmentTree {
    // 0-indexed Segment Tree
    long long n; // 葉の数
    vector<T> data;  // データを格納する配列
    T def;  // 初期値（単位元）
    function<T(T, T)> operation;  // 区間クエリで使う処理
    function<T(T, T)> update;  // 点更新で使う処理

    // 区間 [a, b) に対する query !!!!!
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return data[k];  // a,l,r,bの順で含まれる
        else {
            T c1 = _query(a, b, 2*k+1, l, (l+r)>>1);
            T c2 = _query(a, b, 2*k+2, (l+r)>>1, r);
            return operation(c1, c2);
        }
    }

public:
    // _n: 葉の要素の数, _def: 初期値（単位元）, _operation: クエリの関数, _update: 更新用の関数
    SegmentTree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
        : n(_n), def(_def), operation(_operation), update(_update) {
            n = 1;
            while (n < _n) n<<=1;
            data = vector<T>(2*n-1, def);
        }
    
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i>0) {
            i = (i-1)>>1;
            data[i] = operation(data[i*2+1], data[i*2+2]);
        }
    }

    // 区間 [a, b) に対する query !!!!!
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    T operator[](int i) {
        return data[i+n-1];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vll a(n), h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    SegmentTree<ll> seg(n, 0LL,
        [&](ll i, ll j) {return max(i, j);},
        [&](ll i, ll j) {return j;});
    V<int> ord(n); iota(ALL(ord), 0);
    sort(ALL(ord), [&](int i, int j) {return h[i] < h[j];});
    for (int idx: ord) {
        seg.change(idx, seg.query(0, idx) + a[idx]);
    }
    cout << seg.query(0, n) << '\n';
    return 0;
}
