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

    if (8 < a || 8 < b) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }

    return 0;
}
