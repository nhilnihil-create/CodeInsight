#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    rep(i, m) {
        int _a;
        cin >> _a;
        a[_a] = 1;
    }

    int costToN = 0;
    for(int i = x + 1; i < n; i++) {
        costToN += a[i];
    }

    int costToZero = 0;
    for(int i = x - 1; i != 0; i--) {
        costToZero += a[i];
    }
    cout << min(costToN, costToZero) << endl;
}