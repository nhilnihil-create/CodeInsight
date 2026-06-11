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
int n, m, d, x, ans;

int main() {
    cin >> n >> d >> x;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        ans += (d + m - 1) / m;
    }
    cout << x + ans << endl;

    return 0;
}
