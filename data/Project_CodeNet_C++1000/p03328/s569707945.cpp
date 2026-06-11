#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = (b - a + 1) * (b - a) / 2 - b;
    cout << ans << endl;

    return 0;
}
