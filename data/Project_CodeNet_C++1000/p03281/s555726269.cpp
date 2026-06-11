#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int cnt(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) sum++;
    }
    return sum;
}

signed main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 3; i <= n; i += 2) {
        if (cnt(i) == 8) ans++;
    }
    cout << ans << "\n";
}