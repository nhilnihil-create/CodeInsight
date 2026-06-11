#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

vi v[100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        v[i].pb(i);
        if (n % 2) v[i].pb(n - i);
        else v[i].pb(n + 1 - i);
    }
    if (n % 2) v[n / 2 + 1].pb(n);
    vector<ii> ans;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = i + 1; j <= (n + 1) / 2; j++) {
            for (int u : v[i]) for (int o : v[j]) {
                ans.pb({u, o});
            }
        }
    }
    cout << ans.size() << '\n';
    for (ii u : ans) cout << u.x << ' ' << u.y << '\n';
    return 0;
}