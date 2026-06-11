#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
