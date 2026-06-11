#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> X[i] >> Y[i];
    }
    vector<ll> xx(X), yy(Y);
    auto comp = [](vector<ll>& u) {
        vector<ll> v(u);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for ( int i = 0; i < v.size(); i++ ) {
            u[i] = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
        }
    };
    comp(xx);
    comp(yy);
    vector<ll> x2X(N), y2Y(N);
    vector<vector<ll>> c(xx.size()+1, vector<ll>(yy.size()+1));
    for ( int i = 0; i < N; i++ ) {
        c[xx[i]+1][yy[i]+1] = 1;
        x2X[xx[i]] = X[i]; 
        y2Y[yy[i]] = Y[i]; 
    }
    for ( int i = 1; i <= xx.size(); i++ ) {
        for ( int j = 0; j <= yy.size(); j++ ) {
            c[i][j] += c[i-1][j];
        }
    }
    for ( int j = 1; j <= yy.size(); j++ ) {
        for ( int i = 0; i <= xx.size(); i++ ) {
            c[i][j] += c[i][j-1];
        }
    }
    ll ans = 1LL << 62;
    for ( int xl = 0; xl < xx.size(); xl++ ) {
        for ( int xr = xl+1; xr < xx.size(); xr++ ) {
            for ( int yl = 0; yl < yy.size(); yl++ ) {
                for ( int yr = yl+1; yr < yy.size(); yr++ ) {
                    ll x1 = xl, x2 = xr, y1 = yl, y2 = yr;
                    if ( x1 > x2 ) swap(x1,x2);
                    if ( y1 > y2 ) swap(y1,y2);
                    ll k = c[x2+1][y2+1] - c[x1][y2+1] - c[x2+1][y1] + c[x1][y1];
                    if ( k < K ) continue;
                    ll m = (x2X[x2] - x2X[x1]) * (y2Y[y2] - y2Y[y1]);
                    ans = min(ans, m);
                }
            }
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}