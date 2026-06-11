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

const int N = 105;
int n, ans;
int a[2][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
        if (i > 0)
            a[0][i] += a[0][i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[1][i];
        if (i > 0)
            a[1][i] += max(a[1][i - 1], a[0][i]);
        else
            a[1][i] += a[0][i];
    }
    cout << a[1][n - 1] << endl;
    return 0;
}
