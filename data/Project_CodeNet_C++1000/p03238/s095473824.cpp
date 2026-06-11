#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int n, a, b;
    cin >> n;
    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}
