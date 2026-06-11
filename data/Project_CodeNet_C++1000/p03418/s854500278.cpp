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

const int N = 1e5 + 5;
int n, k;
ll ans;

int main() {
    cin >> n >> k;
    if (k == 0) {
        cout << 1LL * n * n << endl;
        exit(0);
    }

    for (int b = k + 1; b <= n; ++b) {
        // r = (k, b - 1);
        int a = b - k;
        int cnt = n / b;
        ans += cnt * a;
        // cnt * b + (k, b - 1)
        int r = n % b;
        if (r >= k)
            ans += r - k + 1;
    }
    cout << ans << endl;
    return 0;
}
