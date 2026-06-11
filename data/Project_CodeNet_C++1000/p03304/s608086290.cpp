#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    double n, m, d;
    cin >> n >> m >> d;
    double res;
    if (d == 0)
        res = (m - 1) / n;
    else
        res = 2 * (m - 1) * (n - d) / n / n;
    cout << fixed << setprecision(10) << res << endl;
}