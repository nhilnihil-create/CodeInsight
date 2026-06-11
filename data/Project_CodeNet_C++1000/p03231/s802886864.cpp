#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, CC = 10001;

using namespace std;

string s, t;
int n, m;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    int lc = n * m / __gcd(n, m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[i * m] = i;
    }
    for (int i = 0; i < m; i++) {
        if (mp.find(i * n) != mp.end()) {
            if (t[i] != s[mp[i * n]]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << lc;
    return 0;
}
