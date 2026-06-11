#include "bits/stdc++.h"

using namespace std;

const int MAX = 100000;

int powint(int x, int n) {
    int ret = 1;
    while (n > 0) {
        ret *= x;
        --n;
    }
    return ret;
}

int dp(int curr, int N, const vector<int>& withdrawable, vector<vector<int>>& memo) {
    if (curr == withdrawable.size()) {
        return N;
    }
    if (memo[curr][N] >= 0) {
        return memo[curr][N];
    }

    int w = withdrawable[curr];
    int n = N / w;
    int ret = MAX;
    for (int i = 0; i <= n; ++i) {
        if (N - w * i >= 0) {
            int d = i + dp(curr + 1, N - w * i, withdrawable, memo);
            ret = min(ret, d);
        }
    }
    memo[curr][N] = ret;
    return ret;
}

void Main() {
    int N;
    cin >> N;

    vector<int> withdrawable;
    for (int i = 1; i <= 5; ++i) {
        withdrawable.push_back(powint(9, i));
    }
    for (int i = 1; i <= 6; ++i) {
        withdrawable.push_back(powint(6, i));
    }
    vector<vector<int>> memo(withdrawable.size() + 10, vector<int>(N + 10, -1));
    int ans = dp(0, N, withdrawable, memo);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
