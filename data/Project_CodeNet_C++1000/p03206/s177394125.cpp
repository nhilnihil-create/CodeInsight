#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int d;
    cin >> d;

    switch (d) {
    case 22:
        cout << "Christmas Eve Eve Eve" << endl;
        break;
    case 23:
        cout << "Christmas Eve Eve" << endl;
        break;
    case 24:
        cout << "Christmas Eve" << endl;
        break;
    case 25:
        cout << "Christmas" << endl;
        break;

    default:
        break;
    }

    return 0;
}
