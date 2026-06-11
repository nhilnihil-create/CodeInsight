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
    cout << fixed << setprecision(12);


    int n, K;
    cin >> n >> K;

    vector<pair<int,int>> P;
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        P.emplace_back(x, y);
        X.emplace_back(x);
        Y.emplace_back(y);
    }

    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    int h = X.size();
    int w = Y.size();

    for (auto& p : P) {
        int& x = p.first;
        int& y = p.second;
        x = lower_bound(X.begin(), X.end(), x) - X.begin();
        y = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
    }

    auto area = [&](long long l, long long r, long long t, long long b) {
        return (r - l) * (b - t);
    };

    long long res = 1LL << 62;
    vector<int> cnts(w, 0);

    for (int l = 0; l < h; ++l) {
        for (int r = l; r < h; ++r) {
            for (int i = 0; i < w; ++i) {
                cnts[i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                int x = P[i].first, y = P[i].second;
                if (l <= x && x <= r) {
                    cnts[y] += 1;
                }
            }
            for (int t = 0, b = 0, cnt = 0; t < w; ++t) {
                while (cnt < K && b < w) {
                    cnt += cnts[b++];
                }
                if (cnt >= K) {
                    res = min(res, area(X[l], X[r], Y[t], Y[b - 1]));
                }
                cnt -= cnts[t];
            }
        }
    }


    cout << res << '\n';


    return 0;
}