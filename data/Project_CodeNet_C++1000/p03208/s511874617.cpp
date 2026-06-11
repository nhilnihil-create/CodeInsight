#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h, h + n);
    int ans = h[n - 1];
    for (int i = 0; i <= n - k; ++i) {
        ans = min(ans, h[i + k - 1] - h[i]);
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/