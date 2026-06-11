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
    vector<int> solve(int m, int k) {
        int N = 1 << (m + 1);
        int M = 1 << m;
        if (k >= M) {
            return {};
        }

        vector<int> res;
        if (k == 0) {
            for (int i = 0; i < M; ++i) {
                res.push_back(i);
                res.push_back(i);
            }
            return res;
        }

        int a = 0, b = 0;
        for (int i = 1; i < M; ++i) {
            if (i == k) {
                continue;
            }
            if ((i ^ k) < M && (i ^ k) > 0) {
                a = i;
                b = i ^ k;
                break;
            }
        }

        if (a == 0 || b == 0) {
            return {};
        }

        vector<bool> used(M, false);

        used[a] = used[b] = used[k] = true;
        deque<int> que;
        for (auto x : {k}) {
            que.push_back(x);
        }

        for (int i = 0; i < M; ++i) {
            if (!used[i]) {
                if (que.size() < N) {
                    que.push_back(i);
                }
            }
        }
        que.push_back(a);
        que.push_back(b);
        for (int i = M - 1; i >= 0; --i) {
            if (!used[i]) {
                if (que.size() < N) {
                    que.push_back(i);
                }
            }
        }
        que.push_back(k);
        que.push_back(b);
        que.push_back(a);

        for (auto x : que) {
            res.push_back(x);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, k;
    cin >> m >> k;
    Solution sol;
    auto res = sol.solve(m, k);
    if (res.empty()) {
        cout << -1 << '\n';
    } else {
        int n = res.size();
        for (int i = 0; i < n; ++i) {
            cout << res[i] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}