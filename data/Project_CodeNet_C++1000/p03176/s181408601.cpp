#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

template<class T>
struct segment_tree {
    using F = function<T(T,T)>;
    int n;
    vector<T> data;
    F f;
    T init_v;

    segment_tree(int n_, T init_v, F f) : f(f), init_v(init_v) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1,init_v);
    }

    //kをaに変更
    void update(int k, T a) {
        k += n-1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = f(data[k*2+1],data[k*2+2]);
        }
    }

    //[a,b)のquery,kは節点番号
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return data[k];
        else {
            T vl = query(a,b,k*2+1,l,(l+r)/2);
            T vr = query(a,b,2*k+2,(l+r)/2,r);
            return f(vl,vr);
        }
    }

    T get(int a) {return data[a+n-1];}

    void debug(int a, int b) {
        a += n-1; b += n-1;
        for (int i = a; i <= b; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

ll f(ll a, ll b) {return max(a,b);}

int main() {
    int n; cin >> n;
    vint h(n), a(n);
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];
    segment_tree<ll> seg(n+1,0,f);
    rep(i,n) {
        ll value = seg.query(0,h[i]);
        if (seg.get(h[i]) < value+a[i]) seg.update(h[i],value+a[i]);
    }
    cout << seg.query(0,n+1) << endl;
}