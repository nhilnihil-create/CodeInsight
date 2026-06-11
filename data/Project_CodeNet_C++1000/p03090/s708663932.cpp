#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;
    vector<pair<int, int>> ans;

    int jogai = n;
    if (n % 2 == 1) jogai--;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j <= i) continue;
            if (j == jogai) continue;

            ans.push_back(make_pair(i, j));
        }

        jogai--;
    }

    cout << ans.size() << endl;

    for (auto p : ans) {
        cout << p.first << ' ' << p.second << endl;
    }
}