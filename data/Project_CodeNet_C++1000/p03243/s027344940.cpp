#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans;
    string is;
    rep(n, 1000) {
        is = to_string(i);
        if (is[0] == is[1] && is[1] == is[2]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}
