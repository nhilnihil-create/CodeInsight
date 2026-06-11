#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if (A + B - 1 > N || (lint)A * B < N) {
        cout << -1 << "\n";
        return 0;
    }
    if (B == 1) {
        rep(i, N) {
            cout << i + 1;
            if (i == N - 1) cout << "\n";
            else cout << " ";
        }
        return 0;
    }
    vector<int> ans(N, -1);
    rep(i, (N - A) / (B - 1)) {
        rep(j, B) {
            ans[i * B + j] = (i + 1) * B - (j + 1);
        }
    }
    if ((N - A) % (B - 1)) {
        int x = (N - A) / (B - 1) * B;
        rep(i, (N - A) % (B - 1) + 1) {
            ans[x + i] = x + (N - A) % (B - 1) - i;
        }
    }
    rep(i, N) {
        if (ans[i] == -1) ans[i] = i;
    }
    rep(i, N) {
        cout << ans[i] + 1;
        if (i == N - 1) cout << "\n";
        else cout << " ";
    }
    return 0;
}
