#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long add_a = 0, add_b = 0;
    long long diffs = 0;
    for (int i = 0; i < n; i++) {
        int diff = b[i] - a[i];
        diffs += diff;
        if (diff > 0) add_a += diff / 2;
        else add_b += -1 * diff;
    }

    // cout << add_a << " " << add_b << endl;
    if (add_a >= add_b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
