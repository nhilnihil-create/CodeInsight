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


    auto count = [&](int l, int r, int t, int b) {
        int res = 0;
        for (auto& p : P) {
            int x = p.first, y = p.second;
            if (l <= x && x <= r && t <= y && y <= b) {
                ++res;
            }
        }
        return res;
    };

    auto area = [&](long long l, long long r, long long t, long long b) {
        return (r - l) * (b - t);
    };

    long long res = 1LL << 62;
    for (int l = 0; l < h; ++l) {
        for (int r = l; r < h; ++r) {
            for (int t = 0; t < w; ++t) {
                for (int b = t; b < w; ++b) {
                    int L = X[l], R = X[r], T = Y[t], B = Y[b];
                    if (count(L, R, T, B) >= K) {
                        res = min(res, area(L, R, T, B));
                    }
                }
            }
        }
    }


    cout << res << '\n';


    return 0;
}