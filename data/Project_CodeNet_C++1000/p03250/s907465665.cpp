#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << max({a * 10 + b + c, a + b * 10 + c, a + b + c * 10}) << endl;

    return 0;
}
