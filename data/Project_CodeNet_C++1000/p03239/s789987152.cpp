#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int N, T;
    cin >> N >> T;

    int c, t, min_c = 1e9;
    rep(0, N) {
        cin >> c >> t;
        if (t <= T) {
            min_c = min(min_c, c);
        }
    }

    cout << (min_c != 1e9 ? to_string(min_c) : "TLE") << endl;
}

int main() {
    solve();

    return 0;
}
