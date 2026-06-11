#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> pa(N + 1);
    repp(i, 1, N) {
        pa[i] = pa[i-1] + A[i-1];
    }
    ll ans = LONG_MAX;
    int j1 = 0, j2 = 0, j3 = 0;
    repp(i2, 2, N - 2) {
        // pa[i1], pa[i2]-pa[i1], pa[i3]-pa[i2], pa[N]-pa[i3]
        ll PQ = pa[i2], RS = pa[N] - pa[i2];
        int i1 = lower_bound(pa.begin() + 1, pa.begin() + i2 + 1, PQ / 2.0) - pa.begin();
        int i3 = lower_bound(pa.begin() + i2 + 1, pa.begin() + N + 1, PQ + RS / 2.0) - pa.begin();
        if(i1 > 1) {
            if(abs(2 * pa[i1] - pa[i2]) > abs(2 * pa[i1 - 1] - pa[i2])){
                i1 = i1 - 1;
            }
        }
        if(i3 > i2 + 1) {
            if(abs(2 * pa[i3] - pa[i2] - pa[N]) > abs(2 * pa[i3 - 1] - pa[i2] - pa[N])){
                i3 = i3 - 1;
            }
        }
        ll P = pa[i1], Q = pa[i2] - pa[i1], R = pa[i3] - pa[i2], S = pa[N] - pa[i3];
        ll minSum = min(min(P, Q), min(R, S)), maxSum = max(max(P, Q), max(R, S));
        ans = min(ans, maxSum - minSum);
    }
    cout << ans << "\n";
}