#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
template <class T> void corner(bool flg, T hoge) {
    if (flg) {
        cout << hoge << endl;
        exit(0);
    }
}
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a,d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin >> n;
    inputv(A, n);
    inputv(B, n);

    bitset<33> b[MAX_N],c[MAX_N];
    rep(i, n) {
        b[i] = bitset<33>(A[i]);
        c[i] = bitset<33>(B[i]);
    }

    vl C;
    ll kuri = 0;

    rep(i, 31) {
        a = 0;
      p=0;
      q=0;
        rep(j, n) {
            p+= (b[j][i] ? 1 : 0);
            q += (c[j][i] ? 1 : 0);
        }
        a = n*(p+q) + kuri;
        ans += abs(a % 2) * (1 << i);

        kuri = 0;
      C.clear();

        rep(j, n) {
            C.push_back( A[j]%(1<<(i+1)));
        }

        sort(all(C));
      

        rep(j, n) {
            kuri += lower_bound(all(C), (1<<(i+1))-(B[j])%(1<<(i+1)))-C.begin();
        }
      kuri=n-kuri;
    }

    cout << ans << endl;
}
