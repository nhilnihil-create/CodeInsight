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
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k += abs(a[i] - a[i - 1]);
    }
    k += abs(a[n]);
    for (int i = 1; i <= n; ++i) {
        cout << k - abs(a[i] - a[i - 1]) -
                abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i - 1]) << endl;
    }
    return 0;
}
