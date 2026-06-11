#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}

template <typename T>
struct RSQ {

    //初期化
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RSQ(int n_) : n(), dat(n_ * 4, 0) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    //値の更新
    void update(int i, T x) {
        i += n-1;
        dat[i] = x;
        while(i > 0) {
            i = (i-1)/2;
            dat[i] = gcd(dat[i*2+1],dat[i*2+2]);
        }
    }

    //任意区間の最小値
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        else if(a <= l && r <= b) return dat[k];
        else {
            T v1 = query_sub(a,b,2*k+1,l,(l+r)/2);
            T v2 = query_sub(a,b,2*k+2,(l+r)/2,r);
            return gcd(v1,v2);
        }
    }
};

int main() {
    int N; cin >> N;
    RSQ<ll> S(N);
    REP(i,N) {
        ll a; cin >> a;
        S.update(i,a);
    }
    ll ans = 0;
    REP(i,N) {
        chmax(ans,gcd(S.query(0,i),S.query(i+1,N)));
    }
    cout << ans << endl;
}