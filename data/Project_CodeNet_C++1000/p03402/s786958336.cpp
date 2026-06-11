#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int a, b;
    cin >> a >> b;
    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (i % 2 == 1 && j % 2 == 1 && a > 1) {
                cout << '.';
                --a;
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (i % 2 == 1 && j % 2 == 1 && b > 1) {
                cout << '#';
                --b;
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}