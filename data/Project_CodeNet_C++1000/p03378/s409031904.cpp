#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];

    int count = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] < x)
            count ++;
        else
            break;
    }
    int ans = min(count, m-count);
    cout << ans << endl;
}