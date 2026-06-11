#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll X, Y;
    cin >> X >> Y;

    ll count = 0;
    ll x = X;
    while (x <= Y) {
        ++count;
        x *= 2;
    }
    cout << count << endl;

    return 0;
}
