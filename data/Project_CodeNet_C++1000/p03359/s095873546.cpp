#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= b)
        cout << a << endl;
    else
        cout << a - 1 << endl;

    return 0;
}
