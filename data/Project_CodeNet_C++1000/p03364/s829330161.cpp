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
    vector<string> s(n);
    for (auto &e: s) cin >> e;

    int ans = 0;
    for (int d = 0; d < n; ++d) {
        bool f = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i][(j+d)%n] != s[j][(i+d)%n]) f = false;
            }
        }
        if (f) ans += n;
    }

    cout << ans << endl;

    return 0;
}
