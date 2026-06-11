#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        x -= a.at(i);
        if (x < 0) break;
        ans++;
    }
    if (x > 0) ans--;
    cout << ans << endl;
    return 0;
}