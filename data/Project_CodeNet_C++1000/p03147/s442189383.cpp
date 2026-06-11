#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, last = 0;
    vector<int> a, b;
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for (int i : b) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= i) {
                cnt++;
                while (j < n && a[j] >= i) {
                    j++;
                }
            }
        }
        ans += cnt * (i - last);
        last = i;
    }
    cout << ans << endl;
}

