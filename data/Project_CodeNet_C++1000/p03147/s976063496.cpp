#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int h[n];
    for (int i = 0; i < n; ++i) 
        cin >> h[i];
    int ans = 0;
    bool ok = false;
    while (!ok) {
        int mn = 101;
        int pidx = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] == 0) {
                if (i > 0 && h[i - 1] == 0) {
                    pidx = i + 1;
                    continue;
                }
                for (int j = pidx; j < i; ++j) {
                    h[j] -= mn;
                }
                if (mn != 101) ans += mn;
                pidx = i + 1;
                mn = 101;
                continue;
            }
            mn = min(h[i], mn);
        }
        for (int i = pidx; i < n; ++i) h[i] -= mn;
        if (mn != 101) ans += mn;
        int csum = 0;
        for (int i = 0; i < n; ++i) {
            csum += h[i];
        }
        if (csum == 0) ok = true;
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/