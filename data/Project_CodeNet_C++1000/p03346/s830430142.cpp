#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], f[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = max(f[a[i]], f[a[i] - 1] + 1);
    }
    cout << n - *max_element(f + 1, f + n + 1) << endl;
    return 0;
}