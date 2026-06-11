#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int tot = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (abs(a[i] * n - tot) < abs(a[ans] * n - tot))
            ans = i;
    cout << ans << endl;
    return 0;
}
