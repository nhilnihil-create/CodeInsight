#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int n, m;
    cin >> n >> m;
    Int start = 0;
    Int end = n - 1;
    for (Int i = 0; i < m; ++i) {
        Int l, r;
        cin >> l >> r;
        --l; --r;
        if (l > start) {
            start = l;
        } 
        if (r < end) {
            end = r;
        } 
    }
    if (start > end) {
        cout << 0 << endl;
    } else {
        cout << end - start + 1 << endl;
    }
    return 0;
}
