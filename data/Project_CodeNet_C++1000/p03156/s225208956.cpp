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
    int a, b;
    cin >> a >> b;
    auto index = [&](int x) {
        if (x <= a) {
            return 0;
        } else if (x <= b) {
            return 1;
        } else {
            return 2;
        }
    };

    vector<int> cnts(3, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnts[index(x)] += 1;
    }

    cout << *min_element(cnts.begin(), cnts.end()) << '\n';

    return 0;
}