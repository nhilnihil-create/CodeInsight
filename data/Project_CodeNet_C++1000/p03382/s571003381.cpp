#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 100;

int a[N];
int n, mx, dis = 1e9, num;

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; i++)
	if ((dis >= abs(a[i] - mx / 2) || dis >= abs(a[i] - (mx + 1) / 2)) && a[i] != mx) {
	    dis = min(abs(a[i] - mx / 2), abs(a[i] - (mx + 1) / 2));
	    num = a[i];
	}
    return cout << mx << " " << num, 0;
}