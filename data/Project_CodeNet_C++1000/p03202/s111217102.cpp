#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    auto check = [&](long long mid) {
        vector<pair<int, int>> v;       // (pos1, c - 'a')
        v.emplace_back(0, 0);
        for (int i = 1; i < n; i++) if (a[i - 1] >= a[i]) {
            while (v.back().first > a[i]) v.pop_back();
            // inc
            if (v.back().first == a[i]) {
                v.back().second++;
            } else {
                v.emplace_back(a[i], 1);
            }
            // carry
            while (v.back().second == mid) {
                int pos = v.back().first; v.pop_back();
                if (v.back().first == pos - 1) {
                    v.back().second++;
                } else {
                    v.emplace_back(pos - 1, 1);
                }
            }
            if (v.front().second) return false;
        }
        return true;
    };
    auto binary_search = [&](long long ok, long long ng) {
        // assert(check(ok) == true);
        // assert(check(ng) == false);
        while (abs(ng - ok) > 1) {
            long long mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        return ok;
    };
    bool inc = true;
    for (int i = 0; i + 1 < n; i++) if (a[i] >= a[i + 1]) inc = false;
    if (inc) return !(cout << 1 << endl);
    cout << binary_search(n, 1) << endl;
    return 0;
}
