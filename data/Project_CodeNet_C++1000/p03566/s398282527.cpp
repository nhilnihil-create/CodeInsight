#include <iostream>
#include <iomanip>
using namespace std;

constexpr int MAXT = 2 * 101 * 200, MAXV = 2 * 101;
constexpr double inf = 1e9;
double dp[MAXT][MAXV];

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    int T[100], V[100];

    for(int i=0; i < N; ++i) cin >> T[i];
    for(int i=0; i < N; ++i) cin >> V[i];

    // memorize max v of each area
    int cur = 0;
    int area_max_v[MAXT];
    for(int i=0; i < N; ++i) {
        for(int j=cur; j < cur + T[i] * 2; ++j) area_max_v[j] = V[i] * 2;
        cur += T[i] * 2;
    }
    //

    // Init DP table
    for(int i=0; i < MAXT; ++i) for(int j=0; j < MAXV; ++j) dp[i][j] = -inf;
    //

    // DP
    dp[0][0] = 0;
    for(int i=0; i < cur; ++i) {
        for(int j=0; j < MAXV; ++j) {
            if(dp[i][j] != -inf && j <= area_max_v[i]){
                if (j > 0) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + j + j - 1);
                if (j + 1 <= area_max_v[i]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + j + j + 1);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + j + j);
            }
        }
    }
    //

    cout << fixed << setprecision(10) << dp[cur][0] / 8.0 << '\n';
    return 0;
}