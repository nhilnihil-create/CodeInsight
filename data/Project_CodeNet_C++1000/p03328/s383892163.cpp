#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int A, B;
    cin >> A >> B;

    vector<int> a(1100);
    iota(a.begin(), a.end(), 1);
    for (int i = 1; i < 1100; i++) {
        a[i] = a[i] + a[i - 1];
    }

    cout << a[B - A - 1] - B << endl;

    return 0;
}
