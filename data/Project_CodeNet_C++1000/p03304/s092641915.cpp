#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    if (d == 0) {
        cout << fixed << setprecision(10) << 1.0 / n * (m - 1) << endl;
    } else {
        cout << fixed << setprecision(10) << 1.0 / n / n * (n - d) * 2 * (m - 1) << endl;
    }
    return 0;
}
