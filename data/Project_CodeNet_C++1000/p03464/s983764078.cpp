#include <bits/stdc++.h>

using namespace std;

int a[100000 + 5];

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];

    long long left = 2, right = 2;
    for (int i = k - 1; i >= 0; i--) {
        left = ((left + a[i] - 1) / a[i]) * a[i];
        right = (right / a[i]) * a[i] + a[i] - 1;
        if (right < left) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << left << " " << right << endl;
    return 0;
}
