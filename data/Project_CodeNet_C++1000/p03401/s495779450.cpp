#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    ll a[n + 2], sum = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += abs(cur - a[i]);
        cur = a[i];
        if (i == n) sum += abs(cur - 0);
    }
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cout << sum - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) + abs(a[i - 1] - a[i + 1]) << '\n';
    }
}