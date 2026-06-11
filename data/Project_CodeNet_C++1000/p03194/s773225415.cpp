#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;

    long long ans = 1;
    for (int i = 2; 1LL * i * i <= p; i++) {
        int cnt = 0;
        while (p % i == 0) {
            p /= i;
            cnt++;
        }

        if (cnt >= n) {
            for (int j = 0; j < cnt / n; j++) {
                ans *= 1LL * i;
            }
        }
    }
    if (n == 1) ans *= p;

    cout << ans << endl;

    return 0;
}
