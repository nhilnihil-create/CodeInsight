#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <array>

using namespace std;


template<typename T>
void warshall_floyd(int n, vector<T> &g, vector<T> &dp) {
    for (int k = 0, kv = 0; k < n; ++k, kv += n) {
        for (int i = 0, iv = 0; i < n; ++i, iv += n) {
            for (int j = 0; j < n; ++j) {
                dp[iv + j] = min(dp[iv + j], dp[iv + k] + dp[kv + j]);
            }
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    int n = 10;
    vector<int> c(n * n);
    for (int i = 0, iv = 0; i < n; ++i, iv += n) {
        for (int j = 0; j < n; ++j) {
            cin >> c[iv + j];
        }
    }
    vector<int> a(n);
    fill(a.begin(), a.end(), 0);
    int value;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> value;
            if (value != -1 && value != 1) {
                ++a[value];
            }
        }
    }
    vector<int> dp = c;
    warshall_floyd(n, c, dp);
    int cost = 0;
    for (int i = 0, iv = 0; i < n; ++i, iv += n) {
        cost += dp[iv + 1] * a[i];
    }
    cout << cost << endl;

}
