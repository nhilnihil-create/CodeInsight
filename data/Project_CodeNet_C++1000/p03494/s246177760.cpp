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
int a[N], c[N];

int main() {
    ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ++cnt;
        }
        c[i] = cnt;
    }
    for (int i = 0; i < n; ++i) {
        ans = min(ans, c[i]);
    }
    cout << ans << endl;
    return 0;
}
