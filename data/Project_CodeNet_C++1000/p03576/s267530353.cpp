#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
// if(nextY >= 0 && nextY < H && nextX >= 0 && nextX < W)
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,K; cin >> N >> K;
    vector<PL> D(N);
    vector<ll> X(N), Y(N);
    rep(i, N) {
        int x,y; cin >> x >> y;
        D[i] = {x,y};
        X[i] = x;
        Y[i] = y;
    }

    sort(all(X));
    sort(all(Y));

    ll ans = (X.back() - X.front()) * (Y.back() - Y.front());

    rep(xi, N) {
        reps(xj, xi + 1, N) {
            rep(yi, N) {
                reps(yj, yi + 1, N) {
                    int num = 0;
                    rep(i, N) {
                        if(X[xi] <= D[i].first && X[xj] >= D[i].first && Y[yi] <= D[i].second && Y[yj] >= D[i].second) {
                            ++num;
                        }
                    }
                    if(num >= K) {
                        chmin(ans, (X[xj] - X[xi]) * (Y[yj] - Y[yi]));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
