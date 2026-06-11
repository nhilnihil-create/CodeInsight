#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, M;
    cin >> N >> M;
    vl X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];
    ll ans = 0;

    rep(b,8){
        vc<pair<ll, ll>> P(N);
        ll x = (b & 1) != 0, y = (b & 2) != 0, z = (b & 4) != 0;
        rep(i,N){
            P[i].first += (x ? X[i] : -X[i]);
            P[i].first += (y ? Y[i] : -Y[i]);
            P[i].first += (z ? Z[i] : -Z[i]);
            P[i].second = i;
        }
        sort(all(P), greater<pair<ll,ll>>());

        ll sumx = 0, sumy = 0, sumz = 0;
        rep(j,M){
            ll pi = P[j].second;
            sumx += (x ? X[pi] : -X[pi]);
            sumy += (y ? Y[pi] : -Y[pi]);
            sumz += (z ? Z[pi] : -Z[pi]);
        }
        // cout << x << y << z << " " << sumx << " " << sumy << " " << sumz << endl;
        chmax(ans, abs(sumx) + abs(sumy) + abs(sumz));
    }

    cout << ans << endl;
}