#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    Int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n << endl;
    } else {
        cout << 2 * n << endl;
    }

    return 0;
}
