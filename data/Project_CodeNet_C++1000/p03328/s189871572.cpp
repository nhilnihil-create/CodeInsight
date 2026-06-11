#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    vector<int> h(999);
    for (int i = 1; i <= 999; i++) {
        if (i == 1) h[i] = 1;
        else h[i] = h[i-1] + i;
    }
    int k = b - a;
    int ans = h[k] - b;
    cout << ans << endl;
}