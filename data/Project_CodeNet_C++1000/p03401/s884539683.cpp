#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    a[n + 1] = 0;
    int sum = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum+= abs(r - a[i]);
        r = a[i];
    }
    sum += abs(r - 0);
    for (int i = 1; i <= n; i++) {
        cout << sum + abs(a[i - 1] - a[i + 1]) - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]);
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
