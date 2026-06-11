#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include <iomanip>
int main() {
    cout << fixed << setprecision(12);
    int n, m; cin >> n >> m;
    int d; cin >> d;
    int cnt = (d == 0 ? n : 2 * (n - d));
    cout << 1.0 * cnt * (m - 1) / n / n << endl;
    return 0;
}
