#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 4e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll A, B;
    cin >> A >> B;

    vvc<ll> G(100, vl(100));

    repe(i, 50, 100) rep(j, 100) G[i][j] = 1;

    ll acnt = 0, bcnt = 0;

    bool isok = false;
    rep(i, 100){
        if (i % 2) continue;
        if (isok) break;

        rep(j, 50){
            if (acnt == A - 1){
                isok = true;
                break;
            }
            G[i][j * 2] = 1;
            acnt++;
        }
    }

    isok = false;
    repr(i, 100){
        if (i % 2 == 0) continue;
        if (isok) break;
        rep(j, 50){
            if(bcnt==B - 1){
                isok = true;
                break;
            }
            G[i][j * 2] = 0;
            bcnt++;
        }
    }

    cout << "100 100" << '\n';
    rep(i, 100){
        rep(j, 100) cout << (G[i][j] ? '.' : '#');
        cout << '\n';
    }
}