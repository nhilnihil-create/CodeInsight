#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 303;

int DP[MN][MN][MN];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    string S; cin >> S;
    int N = S.size();
    int K; cin >> K;

    memset(DP, 191, sizeof DP);
    for (int i = 0; i < N; ++i) DP[i][i][0] = 1, DP[i+1][i][0] = 0;

    for (int len = 0; len < N; ++len) {
        for (int i = 0; i+len <= N; ++i) {
            int j = i+len-1;
            if (j < 0) continue;
            for (int k = 0; k <= K; ++k) {
                if (i) DP[i-1][j][k] = max(DP[i][j][k], DP[i-1][j][k]);
                if (j < N-1) DP[i][j+1][k] = max(DP[i][j][k], DP[i][j+1][k]);
                if (i && j < N-1) DP[i-1][j+1][k+(S[i-1]!=S[j+1])] = max(DP[i][j][k]+2, DP[i-1][j+1][k+(S[i-1]!=S[j+1])]);
            }
        }
    }
    cout << *max_element(DP[0][N-1], DP[0][N-1]+K+1);
}
