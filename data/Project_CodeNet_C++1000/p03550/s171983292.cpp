#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, z, w;
    cin >> n >> z >> w;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans;
    if (n > 1) {
        ans = max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1]));
    }else{
        ans = abs(a[0] - w);
    }

    cout << ans << endl;
}