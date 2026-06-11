#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int M = 21;
int n, m, c, t, res;
int b[M];
int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        int sum = c;
        for (int j = 0; j < m; ++j) {
            cin >> t;
            sum += t * b[j];
        }
        if (sum > 0)
            ++res;
    }
    cout << res << endl;
    return 0;
}
