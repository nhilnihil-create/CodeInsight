#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    a.emplace(a.begin(), 0);
    a.emplace(a.end(), 0);
    n += 2;
    auto d = [&](int i, int j) {
        return abs(a[i] - a[j]);
    };
    int sum = 0;
    for (int i = 0; i + 1 < n; i++) sum += d(i, i + 1);
    for (int i = 1; i + 1 < n; i++) {
        cout << sum - d(i - 1, i) - d(i, i + 1) + d(i - 1, i + 1) << endl;
    }
    return 0;
}
