#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> b(N);
    REP(i, N) cin >> b[i];
    vector<int> ans;
    while (b.size() > 0) {
        bool found = false;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == i + 1) {
                b.erase(b.begin() + i);
                ans.push_back(i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
}
