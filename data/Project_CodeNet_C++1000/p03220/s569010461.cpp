#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int h[1005];

int main() {
    FIO
    int n; cin >> n;
    int t, a; cin >> t >> a;
    double _max = 1000000.0, temp = 0.0;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) {
    	temp = t - (h[i]*0.006);
    	if (abs(temp-a) < _max) {
    		_max = abs(temp-a);
    		ans = i;
    	}
    }
    cout << ans << "\n";
    return 0;
}