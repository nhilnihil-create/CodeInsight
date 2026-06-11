#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) {
        init(n);
    }
    void init(int n) {
        SIZE_R = 1;
        while(SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }

    // set, a is 0-indexed
    void set(int a, const Monoid &v) {
        dat[a + SIZE_R] = v;
    }
    void build() {
        for(int k = SIZE_R - 1; k > 0; k--) {
            dat[k] = F(dat[k*2], dat[k*2+1]);
        }
    }

    // update a is 0-indexed
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while(k >>= 1) {
            dat[k] = F(dat[k*2], dat[k*2+1]);
        }
    }

    // get {min-value, min-index}, a and b are 0-indexed
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if(left & 1) vleft = F(vleft, dat[left++]);
            if(right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    // debug
    void print() {
        for (int i = 0; i < SIZE_R; i++) {
            cout << (*this)[i];
            if(i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};


// 最大公約数(ユークリッドの互除法)
// O(log max(a, b))
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n, q, com, x, y;
    cin >> n;
    auto fx = [](int x1, int x2) -> int {return gcd(x1, x2);};
    int ex = 0;
    SegTree<int> seg(n, fx, ex);
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        seg.set(i, a[i]);
    }
    seg.build();

    int ans = 0;
    rep(i, n) {
        int l = seg.get(0, i);
        int r = seg.get(i+1, n);
        chmax(ans, gcd(l, r));
    }
    cout << ans << endl;
}