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
    long long int res = 0;
    long long int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }
    for (long long int b = k + 1; b <= n; b++) {
        res += (n / b) * (b - 1 - k + 1) + max((long long int)0, n % b - k + 1);
        // cout << res << endl;
    }
    cout << res << endl;
}
