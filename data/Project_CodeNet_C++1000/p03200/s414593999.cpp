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
    cin >> s; n = s.size();
    int bc = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') ++bc;
        else ans += bc;
    }
    cout << ans;
    return 0;
}
