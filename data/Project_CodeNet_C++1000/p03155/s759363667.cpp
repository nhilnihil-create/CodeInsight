#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    int n, h, w;
    cin >> n >> h >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;

    return 0;
}
