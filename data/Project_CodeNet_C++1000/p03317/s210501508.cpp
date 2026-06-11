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
int j, n, m, k, ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m == 1) {
            j = i;
        }
    }
    int l = j;
    int r = n - 1 - j;
    int rm = 0;
    rm += l % (k - 1);
    l = l / (k - 1);
    rm += r % (k - 1);
    r = r / (k - 1);
    int ans = l + r;
    if (rm > 0)
        ++ans;
    if (rm > k - 1)
        ++ans;
    cout << ans << endl;

    return 0;
}
