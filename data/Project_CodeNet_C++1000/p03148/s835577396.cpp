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
    int n, k;
    cin >> n >> k;
    // おいしさ、ネタ
    vector<pair<ll, int>> sushi(n);
    for (int i = 0; i < n; ++i) {
        int t;
        ll d;
        cin >> t >> d;
        sushi[i] = {d, t};
    }
    sort(sushi.begin(), sushi.end(), greater<pair<ll, int>>());
    map<int, int> neta_cnt;
    ll deliciousness_base = 0;
    for (int i = 0; i < k; ++i) {
        deliciousness_base += sushi[i].first;
        ++neta_cnt[sushi[i].second];
    }
    const ll neta_base = neta_cnt.size();
    vector<pair<ll, int>> swap_target, swap_cand;
    {
        set<int> selected;
        for (int i = k; i < n; ++i) {
            if (selected.count(sushi[i].second) == 0 && neta_cnt.count(sushi[i].second) == 0) {
                swap_cand.push_back(sushi[i]);
                selected.insert(sushi[i].second);
            }
        }
        map<int, int> temp(neta_cnt);
        for (int i = k - 1; i >= 0; --i) {
            if (temp[sushi[i].second] >= 2) {
                swap_target.push_back(sushi[i]);
                --temp[sushi[i].second];
            };
        }
    }
    // swapを試していく！！
    ll ans = deliciousness_base + neta_base * neta_base;
    {
        ll diff = 0;
        for (int i = 0; i < min(swap_target.size(), swap_cand.size()); ++i) {
            diff -= swap_target[i].first;
            diff += swap_cand[i].first;
            ans = max(ans, deliciousness_base + diff + (neta_base + i + 1) * (neta_base + i + 1));
        }
    }
    cout << ans << endl;
    return 0;
}