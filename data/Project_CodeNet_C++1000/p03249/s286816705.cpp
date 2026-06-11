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

class Solution {
public:
    vector<pair<int,int>> solve(vector<long long>& W) {
        int n = W.size();
        vector<pair<long long,int>> P;
        for (int i = 0; i < n; ++i) {
            P.emplace_back(W[i], i);
        }
        sort(P.begin(), P.end());


        vector<long long> sums(n, 0);
        vector<int> sizes(n, 1);
        vector<int> pars(n, -1);

        for (int i = n - 1; i > 0; --i) {
            int u = P[i].second;
            long long sum = P[i].first;
            long long tar = sum - (n - 2 * sizes[u]);
            if (tar == sum) {
                return {};
            }
            auto it = lower_bound(P.begin(), P.end(), make_pair(tar, -1));
            if (it == P.end()) {
                return {};
            }
            if (it->first != tar || it->second == u) {
                return {};
            }
            int p = it->second;
            sums[p] += sums[u] + sizes[u];
            sizes[p] += sizes[u];
            pars[u] = p;
        }

        if (sums[P[0].second] != P[0].first) {
            return {};
        }

        vector<pair<int,int>> res;
        for (int i = 0; i < n; ++i) {
            if (pars[i] >= 0) {
                res.emplace_back(pars[i], i);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> W(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }
    Solution sol;
    auto res = sol.solve(W);
    if (res.size() != n - 1) {
        cout << "-1\n";
    } else {
        for (auto& e : res) {
            cout << e.first + 1 << " " << e.second + 1 << "\n";
        }
    }

    return 0;
}