#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0)
            {
                cout << ans << endl;
                return 0;
            }
        }
        ans++;
        for (int i = 0; i < n; i++)
            a[i] = a[i] >> 1;
    }
}