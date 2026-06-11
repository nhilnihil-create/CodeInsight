#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long n, m, d; cin >> n >> m >> d;
    double r = (2.0 * (n - d) / n) / n;
    if (d == 0) r = 1.0 / n;

    cout << std::fixed << std::setprecision(15);
    cout << r * (m - 1) << endl;
}
