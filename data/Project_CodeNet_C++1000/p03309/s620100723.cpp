#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    int b = a[(n-1)/2];
    long long ans = 0;
    for (int x: a) ans += abs(x - b);
    cout << ans << endl;
    return 0;
}