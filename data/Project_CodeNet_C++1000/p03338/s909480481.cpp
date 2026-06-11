#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        set<char> l, r;
        rep(j, i) l.insert(s[j]);
        for (int j = i; j < n; j++) r.insert(s[j]);

        int cnt = 0;
        for (auto a : l) {
            for (auto b : r) {
                if (a == b) cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
