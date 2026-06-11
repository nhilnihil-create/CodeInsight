#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}

double dp[3005][3005]; // dp[i+1][j]:i枚目までのコインを投げて，j枚のコインが表になる確率
// dp[i+1][j] = dp[i][j]*(1-p[i]) + dp[i][j-1] * p[i];

int main()
{
    int N;
    cin >> N;
    Fill(dp, 0.0);
    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    dp[0][0] = 1.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i + 1; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
            if (j != 0) {
                dp[i + 1][j] += dp[i][j - 1] * p[i];
            }
        }
    }
    double ans = 0.00;
    for (int j = (N + 1) / 2; j <= N; j++) {
        ans += dp[N][j];
    }
    cout << fixed << setprecision(9);
    cout << ans << endl;
    return 0;
}