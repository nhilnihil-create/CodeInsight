#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n;
double dp[310][310][310];

double rec (int i, int j, int k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if (i > 0) res += rec (i - 1, j, k) * i;
    if (j > 0) res += rec (i + 1, j - 1, k) * j;
    if (k > 0) res += rec (i, j + 1, k - 1) * k;
    res += (double)n;
    res *= 1.0 / (double)(i + j + k);
    return dp[i][j][k] = res;
}

int main() {
    cin >> n;
    int n1 = 0, n2 = 0, n3 = 0;
    double a[n];
    rep (i, 0, n) {
        cin >> a[i];
        if (a[i] == 1) n1++;
        else if (a[i] == 2)
            n2++;
        else
            n3++;
    }
    rep (i, 0, 310) rep (j, 0, 310) rep (k, 0, 310) dp[i][j][k] = -1;

    cout << fixed << setprecision (10) << rec (n1, n2, n3) << "\n";
}
