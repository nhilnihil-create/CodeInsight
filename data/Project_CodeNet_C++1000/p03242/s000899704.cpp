#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        if (n[i] == '1') {
            n[i] = '9';
        } else {
            n[i] = '1';
        }
    }

    cout << n << endl;

    return 0;
}
