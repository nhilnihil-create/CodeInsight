#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
/* -- template -- */

#define max max<ll>
#define min min<ll>

int main() {
    int N, K; cin >> N >> K;
    vector<ll> xx(N), yy(N);
    rep(i, N) cin >> xx[i] >> yy[i];
    vector<ll> x(N), y(N);
    x = xx, y = yy;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = (x[N - 1] - x[0]) * (y[N - 1] - y[0]);
    for(int xi = 0;xi < N;++xi) {
        for(int xj = xi + 1; xj < N;++xj) {
            for(int yi = 0;yi < N;++yi) {
                for(int yj = yi + 1;yj < N;++yj) {
                    int count = 0;
                    ll xl = x[xi], xr = x[xj];
                    ll yl = y[yi], yr = y[yj];

                    for(int i = 0;i < N;++i) {
                        if(xl <= xx[i] && xx[i] <= xr && yl <= yy[i] && yy[i] <= yr)
                            ++count;
                    }
                    if(count >= K)
                        ans = min(ans, 1LL * (xr - xl) * (yr - yl));
                }
            }
        }
    }
    cout << ans << endl;
}
