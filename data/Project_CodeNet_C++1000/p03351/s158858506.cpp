#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
