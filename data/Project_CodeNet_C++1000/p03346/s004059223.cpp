#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
ll  MOD = (1e9+7);
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;
    vector<Abel> dat;
    /* [1, n] */
    BIT(int n) : dat(n+1, UNITY_SUM) {}
    void init(int n) { dat.assign(n+1, UNITY_SUM); }
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i=a; i<(int)dat.size(); i+=i & -i)
            dat[i] = dat[i] + x;
    }
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i=a; i>0; i-=i & -i)
            res = res + dat[i];
        return res;
    }
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b-1) - sum(a-1);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n; cin >> n;
    vector<int> p(n);
    rep(i, n) {
        int x; cin >> x;
        p[--x] = i;
    }
    ll ans = 0;
    rep(i, n) {
        ll cnt = 0, now = p[i];
        while (i < n && now <= p[i]) {
            now = p[i]; ++cnt; ++i;
        }
        if (i != n) --i;
        chmax(ans, cnt);
    }
    cout << n-ans << endl;
    return 0;
}