#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
class SEG {
public:
    const ll INF = -1;
    ll n;
    ll N; //葉の数を入れたい
    vector<ll> dat;
    SEG(ll n):n(n),dat(4 * n){
        for (int i = 0; i < 4 * n; i++) {
            dat[i] = INF;
        }
        N = 1;
        while (N < n) {
            N *= 2;
        }
    } //コンストラクタ

    void update(int i, ll x) {
        i += N - 1;    // i番目の値はindex  i + n - 1に相当
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            if (dat[i * 2 + 1] == -1) {
                dat[i] = dat[i * 2 + 2];
            }
            else if (dat[i * 2 + 2] == -1) {
                dat[i] = dat[i * 2 + 1];
            }
            else {
                dat[i] = gcd(dat[i * 2 + 1], dat[i * 2 + 2]);
            }
        }
    }

    //[a, b)の最小値を求めたい  [l, r):dat[k] の表す区間
    ll query_sub(int a, int b, int k, int l, int r) {
        if ((r <= a) || (b <= l)) return INF;
        else if ((a <= l) && (r <= b)) return dat[k];
        else {
            ll vl = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
            if (vl == -1) return vr;
            if (vr == -1) return vl;
            else return gcd(vl, vr);
        }
    }
    ll query(int a, int b) {
        return query_sub(a, b, 0, 0, N);
    }
};
int main() {
    int n;
    cin >> n;
    SEG tree(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        tree.update(i, a);
    }
    ll M = max(tree.query(1, n), tree.query(0, n - 1));
    for (int i = 1; i < n - 1; i++) {
        ll t = gcd(tree.query(0, i), tree.query(i + 1, n));
        if (t > M) M = t;
    }
    cout << M << endl;
    return 0;
}