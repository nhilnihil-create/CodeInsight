#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, ans;
    b = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 == 0) b *= 2;
    }
    ans = pow(3, n) - b;
    cout << ans << endl;
    return 0;
}