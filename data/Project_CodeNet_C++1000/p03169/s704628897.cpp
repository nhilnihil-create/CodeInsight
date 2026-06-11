#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }

const int maxn = 300 + 7;

int n;
int a[maxn];
int cnt[3];
double dp[maxn][maxn][maxn];

double solve(int z, int o, int t) {
    if (z == n) return 0.0;

    if (dp[z][o][t] > -0.5) return dp[z][o][t];

    double num = n;
    if (o > 0) {
        num += o * solve(z+1,o-1,t);
    }
    if (t > 0) {
        num += t * solve(z,o+1,t-1);
    }
    int three = n - z - o - t;
    if (three > 0) {
        num += three * solve(z,o,t+1);
    }

    double den = n - z;
    return dp[z][o][t] = (num/den);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int k = 0; k < maxn; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 3) cnt[a[i]]++;
    }

    solve(cnt[0],cnt[1],cnt[2]);

    cout << fixed << setprecision(12) << dp[cnt[0]][cnt[1]][cnt[2]] << "\n";
    
    
    return 0;
}
