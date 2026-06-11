//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }

    vvi xs(2);
    
    auto compress = [&](vi &x, int i) {
        rep(i_, n) {
            xs[i].push_back(x[i_]);
        }
        sort(all(xs[i]));
        xs[i].erase(unique(all(xs[i])), xs[i].end());
        rep(i_, n) {
            x[i_] = lower_bound(all(xs[i]), x[i_]) - xs[i].begin();
        }
    };
    
    compress(x, 0);
    compress(y, 1);
    
    int X = xs[0].size();
    int Y = xs[1].size();

    vvi point(X+1, vi(Y+1));


    rep(i, n) {
        point[x[i]+1][y[i]+1]++;
    }

    rep(i, X) {
        rep(j, Y) {
            point[i+1][j+1] += point[i][j+1] + point[i+1][j] - point[i][j];
        }
    }

    ll ans = INT64_MAX;
    rep(i1, X) {
        for(int i2 = i1+1; i2 < X+1; ++i2) {
            rep(j1, Y) {
                for(int j2 = j1+1; j2 < Y+1; ++j2) {
                    int cc = point[i2][j2] - point[i2][j1] - point[i1][j2] + point[i1][j1];
                    if(cc >= k) {
                        ans = min(ans, (xs[0][i2-1]-xs[0][i1])*(xs[1][j2-1]-xs[1][j1]));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}