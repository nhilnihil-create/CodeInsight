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

int n, m;

int main() {
    cin >> n >> m;
    m /= 1000;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j + i <= n; ++j) {
            int k = n - i - j;
            int t = 10 * i + 5 * j + k;
            if (t == m) {
                cout << i << ' ' << j << ' ' << k << endl;
                exit(0);
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
