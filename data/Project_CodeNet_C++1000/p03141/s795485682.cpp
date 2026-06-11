#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
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
    ll N;
    cin >> N;
    vl A(N), B(N);
    vc<pair<ll, ll>> C(N);
    rep(i,N){
        ll a, b;
        cin >> a >> b;
        A[i] = a, B[i] = b, C[i] = {a + b, i};
    }
    sort(all(C));
    reverse(all(C));

    ll ans = 0;
    rep(i,N){
        ll sum, k;
        tie(sum, k) = C[i];
        if(i%2==0){
            ans += A[k];
        }else{
            ans -= B[k];
        }
    }
    cout << ans << endl;
}