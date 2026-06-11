#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N;
    cin >> N;
    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ans;
    while (N) {
        if (N % 2 == 0) ans.push_back(0);
        else ans.push_back(1);
        if (N < 0) N = (-N + 1) / 2;
        else N = -(N / 2);
    }
    reverse(ans.begin(), ans.end());
    for (auto n : ans) cout << n;
    cout << "\n";
    return 0;
}
