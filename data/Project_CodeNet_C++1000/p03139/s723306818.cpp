#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans1 = min(a, b);
    int ans2;
    if(a + b <= n) {
        ans2 = 0;
    } else {
        ans2 = a + b - n;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}