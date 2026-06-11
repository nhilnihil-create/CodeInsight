#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int mn = a[0];

    for (int i = 1; i < n; i++) {
        mn = __gcd(mn, a[i]);
    }

    cout << mn << endl;
}