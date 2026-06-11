#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    int sum = m * 1900 + (n - m) * 100;

    int cnt[6] = {1, 2, 4, 8, 16, 32};
    cout << sum * cnt[m] << endl;

    return 0;
}