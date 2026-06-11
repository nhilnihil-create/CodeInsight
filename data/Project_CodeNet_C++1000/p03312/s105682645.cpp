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
    ll N;
    cin>>N;
    vl A(N);
    rep(i, N) cin >> A[i];
    vl sum(N + 1);
    rep(i, N) sum[i + 1] = sum[i] + A[i];

    ll l = 1, r = 3, ans = INF;
    ll l1, l2, r1, r2;
    repe(c,2,N-1){
        chmax(r, c + 1);
        l1 = sum[l], l2 = sum[c] - sum[l], r1 = sum[r] - sum[c], r2 = sum[N] - sum[r];
        while (l < c - 1 && abs(l2-l1) > abs(l2-l1-2*A[l])) {
            l1 += A[l], l2 -= A[l];
            l++;
        }
        while(r<N-1&&abs(r2-r1)>abs(r2-r1-2*A[r])){
            r1 += A[r], r2 -= A[r];
            r++;
        }
        // cout << l << " " << c << " " << r << endl;
        // cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        auto pl = minmax(l1, l2), pr = minmax(r1, r2);
        chmin(ans, max(pl.second, pr.second) - min(pl.first, pr.first));
    }
    cout << ans << endl;
}