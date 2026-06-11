#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = 1; i <= k; ++i) {
        if(i % 2 == 0) {
            b /= 2;
            a += b;
        }
        else {
            a /= 2;
            b += a;
        }
    }

    cout << a << " " << b;
}