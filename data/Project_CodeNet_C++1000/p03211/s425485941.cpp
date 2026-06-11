#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, ans = LONG_LONG_MAX;
    cin >> x;
    while(x > 99) {
        ans = min(abs(753-(x%1000)), ans);
        x /= 10;
    }
    cout << ans << endl;
    return 0;
}
