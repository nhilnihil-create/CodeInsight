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

int n, t;

int main() {
    cin >> n;
    int mi = 1e9;
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        mi = min(mi, t);
        mx = max(mx, t);
    }
    cout << mx - mi << endl;
    return 0;
}
