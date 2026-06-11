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
    long long int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << max((long long int)0, m - 2) << endl;
        return 0;
    }
    cout << (n - 2) * (m - 2) << endl;
}
