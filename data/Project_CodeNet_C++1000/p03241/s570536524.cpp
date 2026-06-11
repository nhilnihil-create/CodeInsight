#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> fac;

    for (long long x = 1; x * x <= m; x++) {
        if (m % x == 0) {
            fac.push_back(x);
            if (x != m/x)
                fac.push_back(m/x);
        }
    }
    
    sort(fac.begin(), fac.end(), greater<long long>());

    for (auto x : fac) {
        if (m/x >= n) {
            cout << x << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}