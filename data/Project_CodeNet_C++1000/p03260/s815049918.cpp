#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int a, b;
    cin >> a >> b;

    if (a % 2 == 1 && b % 2 == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}