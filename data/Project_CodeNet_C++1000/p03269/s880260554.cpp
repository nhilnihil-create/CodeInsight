#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;

uint32_t popcnt(uint32_t n)
{
    n = (n & 0x55555555) + (n >> 1 & 0x55555555);
    n = (n & 0x33333333) + (n >> 2 & 0x33333333);
    n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
    n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
    return n;
}

int main() {
    int l;
    cin >> l;

    int n = 1;
    while ((1 << n) <= l) ++n;
    int m = 2 * (n-1) + popcnt(l) - 1;

    cout << n << " " << m << endl;

    for (int i = 1; i <= n-1; ++i) {
        cout << i << " " << i+1 << " " << 0 << endl;
        cout << i << " " << i+1 << " " << (1 << (i-1)) << endl;
    }
    for (int i = 1; i <= n-1; ++i) {
        int d = l >> (i-1) & 1;
        if (d == 0) continue;
        int c = l >> i << i;
        cout << i << " " << n << " " << c << endl;
    }

    return 0;
}
