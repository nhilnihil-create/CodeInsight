#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;

    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        if (i%2 == 1) {
            for (int j = 1; j < i/2; j++) {
                if (i%j == 0) sum++;
            }
        }
        if (sum == 7) ans++;
    }

    cout << ans << endl;
    return 0;
}