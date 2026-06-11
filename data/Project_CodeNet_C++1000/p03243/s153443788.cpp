#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 9; i > 0; --i) {
        int t = i * 111;
        if (t >= n) ans = t;
    }
    cout << ans << '\n';
}