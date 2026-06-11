#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n) a[i] = a[i] - (i + 1);

    sort(a.begin(), a.end());

    int b;
    if (n % 2 == 0) {
        b = a[n / 2 - 1];
    } else {
        b = a[(n +1) / 2-1];
    }

    long long int sum = 0;
    rep(i, n) sum += abs(a[i] - b);

    cout << sum << endl;
}
