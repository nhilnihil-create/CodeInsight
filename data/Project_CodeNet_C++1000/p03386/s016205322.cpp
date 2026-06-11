#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    set<int> nums_set;
    if (k < (b - a)) {
        rep(0, k) {
            nums_set.insert(a + i);
            nums_set.insert(b - i);
        }
    } else {
        rep(a, b+1) nums_set.insert(i);
    }

    for (int n : nums_set) cout << n << endl;
}

int main() {
    solve();

    return 0;
}
