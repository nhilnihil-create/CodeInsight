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
#include <cassert>
#include <complex>
#include <bitset>
#include <functional>

using namespace std;
using ll=long long int;

int main() {
    int n;
    cin >> n;

    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    } else if (n == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }

    int a;
    for (a = min(10000, n-1); a > 0; --a) {
        int b = n-a;
        if (a*(a+1)/2 % 2 == 0 && b % 2 == 0) break;
    }

    for (int i = 1; i <= a; ++i) {
        cout << i*3 << " ";
    }
    for (int i = 1, cnt = 0; cnt < n-a; ++i) {
        if (i % 3 == 0) continue;
        cout << i*2 << " ";
        ++cnt;
    }
    cout << endl;

    return 0;
}
