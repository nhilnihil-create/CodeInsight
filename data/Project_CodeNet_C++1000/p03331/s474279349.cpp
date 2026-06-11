#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int sum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int main() {

    int n; cin >> n;

    int ans = INF;
    for (int i = 1; i < n; ++i) {
        int a = i;
        int b = n - i;

        ans = min(ans, sum(a) + sum(b));
    }

    cout << ans << endl;
}