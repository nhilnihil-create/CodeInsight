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
int n, m, k, ans;
int a[201];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ++a[i];
        for (int j = i + i; j <= n; j += i) {
            ++a[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 8 && (i & 1))
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
