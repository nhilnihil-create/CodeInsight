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

int a, b, c, x, ans;
int main() {
    cin >> a >> b >> c >> x;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                int sum = 500 * i + 100 * j + 50 * k;
                if (sum == x)
                    ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
