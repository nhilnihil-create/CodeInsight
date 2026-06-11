#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5010][5010], _min[5010][5010];
int n, A, B;
int a[5010], pos[5010];
int main() {
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(j != pos[i]) {
                dp[i][j] = _min[i - 1][j] + (j > pos[i] ? A : B);
            }
            else if(j == pos[i]) {
                dp[i][j] = min(_min[i - 1][j] + B, _min[i - 1][j - 1]);
            }
            if(j == 0) _min[i][j] = dp[i][j];
            else _min[i][j] = min(_min[i][j - 1], dp[i][j]);
        }
    }
    return cout << _min[n][n] << endl, 0;
}