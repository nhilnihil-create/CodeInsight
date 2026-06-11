// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;

    double res = 0.0;

    // 出た目をxとする。
    for (int x = 1; x <= N; x++) {
        double p = 1.0 / (double)N;  // 確率
        int X = x;
        while (X < K) {
            X *= 2;
            p *= 0.5;
        }
        res += p;
    }

    cout << std::fixed << std::setprecision(15);
    cout << res << endl;
}