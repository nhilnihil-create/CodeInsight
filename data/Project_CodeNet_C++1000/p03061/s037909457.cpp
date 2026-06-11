#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int GCD(int x, int y) {
    if (y == 0) return x;
    return GCD(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int a[n]; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(n, 1), r(n, 1);
    l[0] = a[0];

    for (int i = 0; i < n - 1; ++i) {
        l[i + 1] = GCD(l[i], a[i + 1]);
    }

    r[n - 1] = a[n - 1];
    for(int i = n - 1; i > 0; --i) {
        r[i - 1] = GCD(r[i], a[i - 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) ans = max(ans, r[i + 1]);
        else if (i == n - 1) ans = max(ans, l[i - 1]);
        else ans = max(ans, GCD(r[i + 1], l[i - 1]));
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/