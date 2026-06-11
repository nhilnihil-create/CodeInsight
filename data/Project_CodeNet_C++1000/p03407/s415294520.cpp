#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << '\n'

typedef int64_t Int;
const double pi = M_PI;

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool ans = true;

    if (a + b < c) {
        ans = false;
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
