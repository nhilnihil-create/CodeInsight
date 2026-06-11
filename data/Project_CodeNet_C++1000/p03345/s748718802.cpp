#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;

    long long d = a - b;

    if (k % 2 != 0)
        d = -d;

    cout << d << endl;
}