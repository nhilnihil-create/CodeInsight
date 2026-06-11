#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (ab.size() == 0 || ab.back().second != a) {
            ab.emplace_back(b, a);
        }
    }
    sort(ab.begin(), ab.end());
    int ans = 0;
    int last = 0;
    for (auto&& e : ab) {
        if (e.second >= last) {
            ans++;
            last = e.first;
        }
    }
    cout << ans << endl;
}
