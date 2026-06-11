#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int x[m];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    if (m <= n) {
        cout << 0 << "\n";
        return 0;
    }
    sort(x, x + m);;
    vector<int> d;
    for (int i = 0; i < m - 1; ++i) {
        d.PB(abs(x[i] - x[i + 1]));
        ans += d[i];
    }
    sort(d.rbegin(), d.rend());
    for (int i = 0; i < n - 1; ++i) {
        ans -= d[i];
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/