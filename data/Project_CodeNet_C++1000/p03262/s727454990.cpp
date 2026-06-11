#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n, p;
    cin >> n >> p;
    set<int> s;
    s.insert(p);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> a;
    auto f = s.begin();
    int prev = *f;
    f++;
    while(f != s.end()) {
        a.push_back(*f - prev);
        prev = *f;
        f++;
    }
    int ans = a[0];
    for (int i = 1; i < (int) a.size(); i++) {
        ans = __gcd(ans, a[i]);
    }
    cout << ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
