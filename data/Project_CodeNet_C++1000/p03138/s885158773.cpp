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
    int n;
    cin >> n;
    long long int k;
    cin >> k;
    vector<long long int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long int res1 = 0, res2 = -1;
    for (int i = 62; i >= 0; i--) {
        long long int zero = 0, one = 0;
        long long int base = 1;
        // res1 == , res2 <
        long long int next_res1 = 0, next_res2 = -1;
        for (auto num : v) {
            if ((num >> i) % 2 == 1) {
                one++;
            } else {
                zero++;
            }
        }
        if ((k >> i) % 2 == 1) {
            if (res2 > 0)
                next_res2 = max(res2 + max(one, zero) * (base << i), res1 + one * (base << i));
            else
                next_res2 = res1 + one * (base << i);
            next_res1 = res1 + zero * (base << i);
        } else {
            next_res1 = res1 + one * (base << i);
            if (res2 > 0) next_res2 = max(one, zero) * (base << i) + res2;
        }
        res1 = next_res1;
        res2 = next_res2;
    }

    cout << max(res1, res2) << endl;
}
