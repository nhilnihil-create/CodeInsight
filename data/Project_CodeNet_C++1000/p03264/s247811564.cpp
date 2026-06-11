#include <bits/stdc++.h>
using namespace std;


int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) ans += n - i + 1;
    }
    cout << ans << '\n';
    return 0;
}
