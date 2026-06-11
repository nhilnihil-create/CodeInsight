#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, k; cin >> a >> b >> k;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0) {
            if (a % 2 == 1) a--;
            b += a / 2;
            a /= 2;
        } else {
            if (b % 2 == 1) b--;
            a += b / 2;
            b /= 2;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}