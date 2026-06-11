#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while (q-- > 0) {
        long long a, b;
        cin >> a >> b;

        long long c = (long long) (sqrt(a * b - 1) + 0.5);
        if (c * c >= a * b) {
            --c;
        }
        long long res = 2 * c;
        if (c * (c + 1) >= a * b) {
            --res;
        }
        if (c >= a || c >= b) {
            --res;
        }
        
        cout << res << '\n';
    }

    return 0;
}