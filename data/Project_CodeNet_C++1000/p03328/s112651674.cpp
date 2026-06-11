#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int idx = 0, val = 2;
    vector<int> tower;
    tower.push_back(1);
    while (val < 1000) {
        tower.push_back(tower[idx] + val);
        idx++; val++;
    }

    int ans;
    for (int i = 1; i < tower.size(); i++) {
        if (tower[i] - tower[i-1] == b - a) {
            ans = tower[i-1] - a;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}
