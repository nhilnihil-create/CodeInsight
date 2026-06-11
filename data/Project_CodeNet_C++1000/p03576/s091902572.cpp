#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    vector<ll> X(N), Y(N);
    REP(i, 0, N) cin >> X[i] >> Y[i];

    vector<ll> xx = X, yy = Y;
    sort(ALL(xx)); xx.erase(unique(ALL(xx)), xx.end());
    sort(ALL(yy)); yy.erase(unique(ALL(yy)), yy.end());

    vector<vector<int>> P(N, vector<int>(N, 0));
    REP(i, 0, N) {
        X[i] = lower_bound(ALL(xx), X[i]) - xx.begin();
        Y[i] = lower_bound(ALL(yy), Y[i]) - yy.begin();
        P[X[i]][Y[i]]++;
    }
    
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
    REP(i, 0, N) {
        REP(j, 0, N) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + P[i][j];
        }
    }

    ll ans = (1LL << 62);
    REP(i, 0, N) {
        REP(j, 0, N) {
            REP(k, i + 1, N + 1) {
                REP(l, j + 1, N + 1) {
                    if (sum[k][l] - sum[k][j] - sum[i][l] + sum[i][j] >= K) {
                        ans = min(ans, (xx[k - 1] - xx[i]) * (yy[l - 1] - yy[j]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}