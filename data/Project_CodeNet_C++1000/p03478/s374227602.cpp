#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int hold = i, sum = 0;
        while (hold) {
            sum += hold % 10;
            hold /= 10;
        }
        if (a <= sum && sum <= b) {
            res += i;
        }
    }
    cout << res;
    return 0;
}