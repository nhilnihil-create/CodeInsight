#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

int c[5003][5003], d[5003][5003];

int main() {
    ios::sync_with_stdio(false);
    int n, p[5003] = {};
    ll a, b, z[5003];
    cin >> n >> a >> b;
    fr1(n) cin >> p[i];
    fr1(n) for (int j = 1; j <= n; j++) c[i][j] = c[i - 1][j] + (p[i] < j), d[i][j] = d[i - 1][j] + (p[i] > j);
    fr1(n) z[i] = a * (i - 1);
    fr1(n) for (int j = 1; j < i; j++) if (p[i] > p[j]) z[i] = min(z[i], z[j] + b * (c[i - 1][p[j]] - c[j][p[j]]) + a * (d[i - 1][p[i]] - d[j][p[i]]) + min(a, b) * (i - j - 1 - c[i - 1][p[j]] + c[j][p[j]] - d[i - 1][p[i]] + d[j][p[i]]));
    fr1(n) z[i] += b * (n - i);
    //fr1(n) cout << z[i] << ' ';
    fr1(n) z[n] = min(z[n], z[i]);
    cout << z[n];
}
