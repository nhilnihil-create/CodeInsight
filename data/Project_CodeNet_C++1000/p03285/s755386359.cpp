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

    int n;
    cin >> n;

    int a = 4, b = 7;

    bool res = false;
    for (auto x : {a, b}) {
        if (n % x == 0 && n / x >= 2) {
            res = true;
            break;
        }
    }
    {
        for (int i = 0; i <= n / a; ++i) {
            for (int j = 0; j <= n / b; ++j) {
                if (i * a + j * b == n) {
                    res = true;
                }
            }
        }
    }

    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}