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

const int N = 1e5 + 5;
int n, m, k, ans;

int main() {
    cin >> n >> m;
    for (int i = n; i <= m; ++i) {
        if (m % i == 0) {
            cout << m / i << endl;
            exit(0);
        }
    }
    return 0;
}
