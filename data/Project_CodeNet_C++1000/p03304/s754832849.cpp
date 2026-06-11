#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    cout << setprecision(20);
    if (d == 0) {
        cout << 1.0 * (n - d) * (m - 1) / n / n << endl;
    } else {
        cout << 2.0 * (n - d) * (m - 1) / n / n << endl;
    
    }
}
