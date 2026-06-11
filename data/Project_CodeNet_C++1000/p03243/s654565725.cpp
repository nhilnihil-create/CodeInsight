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

    auto ok = [&](int x) {
        int d = x % 10;
        while (x != 0) {
            if (d != x % 10) {
                return false;
            }
            x /= 10;
        }
        return true;
    };
    while (true) {
        if (ok(n)) {
            break;
        }
        ++n;
    }
    cout << n << '\n';

    return 0;
}