#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 301;

int n, f[4];
bool memo[N][N][N];
double p, ev[N][N][N];

double dp(int x, int y, int z) {
    int w = x + y + z;
    if (!w) return 0;
    if (memo[x][y][z])
        return ev[x][y][z];
    w = n - w;

    double ans = 0.0;
    double px = x * p;
    double py = y * p;
    double pz = z * p;
    if (x) ans += px * (1.0 + dp(x - 1, y, z));
    if (y) ans += py * (1.0 + dp(x + 1, y - 1, z));
    if (z) ans += pz * (1.0 + dp(x, y + 1, z - 1));

    double pw = w * p;
    double bt = 1.0 / (1.0 - pw);
    ans *= bt;
    ans += pw * bt;

    memo[x][y][z] = 1;
    return ev[x][y][z] = ans;
}

void solve() {
    cin >> n;
    fill(f, f + 4, 0);
    for (int i = 0, a; i < n; i++)
        cin >> a, f[a]++;
    for (int i = 0; i <= f[1] ; i++)
        for (int j = 0; j <= f[2]; j++) {
            fill(ev[i][j], ev[i][j] + f[3] + 1, 0.0);
            fill(memo[i][j], memo[i][j] + f[3] + 1, 0);
        }
    p = 1.0 * n;
    p = 1.0 / p;
    cout << dp(f[1], f[2], f[3]) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << setprecision(15);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
