#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int n, m;
    cin >> n >> m;
    VI x(m);
    for (Int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    VI diff(m - 1);
    for (Int i = 0;i < m - 1; ++i) {
        diff[i] = x[i + 1] - x[i];
    }
    sort(diff.begin(), diff.end());
    Int result = 0;
    for (Int i = 0; i < m - n; ++i) {
        result += diff[i];
    }
    cout << result << endl;
    return 0;
}

