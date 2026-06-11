#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, ans;
int c(int x, int y) {
    int base = y;
    int cnt = 0;
    while (base * y <= x) {
        base *= y;
    }
    while (x) {
        cnt += x / base;
        x %= base;
        base /= y;
    }
    return cnt;
}

int main() {
    cin >> n;
    ans = n;
    for (int i = 0; i * 9 <= n; ++i) {
        int j = (n - i * 9) / 6;
        int r = n - i * 9 - j * 6;
        int a = c(i, 9);
        int b = c(j, 6);
        ans = min(ans, r + a + b);
    }
    cout << ans << endl;
    return 0;
}
