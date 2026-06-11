#include <bits/stdc++.h>

using namespace std;

long double n, m, d, times;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m >> d;
    if(d == 0)
        times = 1 / n;
    else
        times = (2 * (n - d)) / (n * n);
    cout << setprecision(15) << fixed << times * (m - 1) << "\n";
}
