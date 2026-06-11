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
using P = pair<ll, ll>;

int main() {
    init();
    ll N,K;
    cin >> N >> K;
    vc<P> p(N);
    rep(i, N) cin >> p[i].first >> p[i].second;

    sort(all(p), [](P p1, P p2) { return p1.first < p2.first; });

    vc<P> I;
    ll ans = INF;
    rep(i, N - 1){
        repe(j, i + K, N + 1){
            I.clear();
            repe(k, i, j) I.eb(p[k]);
            ll isize = I.size();
            sort(all(I), [](P p1, P p2) { return p1.second < p2.second; });

            rep(k, isize - K + 1) chmin(ans, (p[j - 1].first - p[i].first) * (I[k + K - 1].second - I[k].second));
        }
    }

    cout << ans << endl;
}