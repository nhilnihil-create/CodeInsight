#include <bits/stdc++.h>
using namespace std;

void solve () {
    string s;
    cin >> s;
    int n = (int) s.size();
    string corr, corr2;
    for (int i = 0; i < n; i++) {
        corr += i % 2 ? '1' : '0';
        corr2 += i % 2 ? '0' : '1';
    }
    vector<int> ans(2);
    for (int i = 0; i < n; i++) {
        ans[0] += s[i] == corr[i] ? 1 : 0;
        ans[1] += s[i] == corr2[i] ? 1 : 0;
    }
    cout << min (ans[0], ans[1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
