#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    vector<set<char>> st(n);
    rep(i,n) {
        st[i].insert(a[i]);
        st[i].insert(b[i]);
        st[i].insert(c[i]);
    }
    rep(i,n) {
        ans += st[i].size() - 1;
    }
    cout << ans << endl;
}