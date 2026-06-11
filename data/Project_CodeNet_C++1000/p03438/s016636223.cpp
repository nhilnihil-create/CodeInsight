#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int d[n];
    for (int i = 0; i < n; i++) {
        d[i] = a[i] - b[i];
    }
    ll s = 0;
    ll k = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] >= 0) s += d[i];
        else k += -(d[i] / 2);
    }

    cout << ((s <= k) ? "Yes" : "No") << endl;
    return 0;
}