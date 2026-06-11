#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int a, b, c, d, e;
    vector<int> dishes(5);
    rep(i, 5) cin >> dishes[i];
    int m = dishes[0] % 10;
    int idx = 0;
    for(int i = 1; i < 5; i++) {
        if(dishes[i] % 10 < m && dishes[i] % 10 > 0) {
            m = dishes[i] % 10;
            idx = i;
        }
    }
    int ans = 0;
    rep(i, 5) {
        if(idx == i)
            ans += dishes[i];
        else if(dishes[i] % 10 == 0)
            ans += dishes[i];
        else
            ans += dishes[i] - dishes[i] % 10 + 10;
    }
    cout << ans << endl;
}