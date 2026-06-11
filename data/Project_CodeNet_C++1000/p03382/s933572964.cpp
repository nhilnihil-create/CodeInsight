#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > l) {
            l = a[i];
        }
    }
    int output = 0;
    if (l % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (abs(l / 2 - a[i]) < abs(l / 2 - output) && a[i] != l) {
                output = a[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (abs(l / 2 + 1 - a[i]) < abs(l / 2 + 1 - output) && a[i] != l) {
                output = a[i];
            }
        }
    }

    cout << l << " " << output << endl;

    return 0;
}
