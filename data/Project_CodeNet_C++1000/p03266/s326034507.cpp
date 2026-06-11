#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;

    ll a = 0, b = 0;
    bool isEven = k % 2 == 0;
    for (ll i = 1; i <= n; i++) {
        if (i % k == 0) a++;
        if (isEven)
            if (i % k == k / 2) b++;
    }

    cout << a * a * a + b * b * b << endl;
    return 0;
}
