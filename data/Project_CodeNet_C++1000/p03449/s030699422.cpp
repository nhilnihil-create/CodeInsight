#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(n);
    rep(i, n) cin >> a1[i];
    rep(i, n) cin >> a2[i];
    int ans = 0, current = 0;
    rep(i, n) {
        current = 0;
        rep(j, i + 1) current += a1[j];
        for(int k = i; k < n; k++)
            current += a2[k];

        ans = max(ans, current);
    }
    cout << ans << endl;
}