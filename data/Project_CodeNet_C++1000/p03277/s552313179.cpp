#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
using namespace std;
/*
struct Monoid {
    using T = _underlying_set_;
    static  T op(const T& a, const T& b) { return _a_op_b_; }
    static constexpr T id() { return _identity_element_; }
    static T update(const T& a,const T& b) {return _a_update_b_;}
};
*/

template <class Monoid>
class SegTree {
   private:
    using T = typename Monoid::T;
    const size_t n;
    vector<T> t;
    void prop_to(size_t i) { t[i] = Monoid::op(t[2*i+1],t[2*i+2]); }
    // 更新
   public:
    SegTree(size_t m,T val) : n(m){
        t.resize(2*n-1,Monoid::id());
        for (long long i = 0;i < n;i++) t[i+(n-1)] = val;
        for (long long i = (n-2); i >= 0; --i) prop_to(i);
    }

    SegTree(vector<T> &a)
        : n(a.size()){ 
        t.resize(2*n-1,Monoid::id());
        for (long long i = 0;i < n;i++) t[i+(n-1)] = a[i];
        for (long long i = (n-2); i >= 0; --i) prop_to(i);
    }

    T operator[](size_t i) {return t[i+(n-1)];} // 列のi番目を返す

    void update(size_t i, const T& v) { // 列のi番目に対し、vを作用。
        t[i += (n-1)] = Monoid::update(t[i],v);
        while (i && ((--i) >>= 1)) prop_to(i);
        if(n >= 2) prop_to(0);
    }

    T find(size_t l, size_t r) { // [l,r)の範囲で見つける。
        T accl = Monoid::id(), accr = Monoid::id();
        for (l += (n-1), r += (n-1); l < r; l >>= 1, (--r) >>= 1) {
            if(!(l & 1)) accl = Monoid::op(accl, t[l]);
            if(!(r & 1)) accr = Monoid::op(t[r-1], accr);
        }
        return Monoid::op(accl, accr);
    }
};

struct RSQ { //区間の合計
    using T = long long;
    static T op(const T&a,const T& b) {return a+b;}
    static constexpr T id() {return 0;}
    static T update(const T& a,const T& b) {return a+b;}
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<long long> a(N);
    vector<long long> sub_mid(N+1);
    REP(i,N) cin >> a[i];

    // aの降順ソート
    vector<long long> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end(), greater<long long>() );

    // 二分探索
    long long pairn = (N+1)*(N)/2;
    long long ng = (-1);
    long long ok = a.size() - 1;

    while (abs(ok - ng) > 1) {
        long long mid_idx = (ok + ng) / 2; // 中央値の候補のindex
        long long mid = sorted_a[mid_idx]; // 中央値の候補
        sub_mid[0] = 0; // 余分に作る

        long long potential = 0;
        REP(i,N) {
            // 中央値の候補以上 -> 1 , その他 -> -1 に置き換え.
            if (a[i] >= mid) sub_mid[i+1] = 1; 
            else sub_mid[i+1] = (-1);

            // 累積和
            sub_mid[i+1] += sub_mid[i];
            // 後でsub_midから負の値をなくす用.
            potential = min(sub_mid[i+1],potential);
        }

        // BITとして使う.転倒数 inversion を算出.
        SegTree<RSQ> sg(N+1,0);
        long long inversion = 0;
        REP(i,N+1) {
            inversion += (i - sg.find(0,(sub_mid[i]-potential)+1));
            sg.update((sub_mid[i]-potential),1);
        }

        // pairn - inversion : Sl <= Srの通り数 
        // if ( (pairn - inversion)*2 >= pairn ) <=>
        if (pairn >= inversion*2) ok = mid_idx;
        else ng = mid_idx;
    }
    cout << sorted_a[ok] << endl;
}


