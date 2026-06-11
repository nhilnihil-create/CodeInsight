#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    int n, cnt[26];
    cin >> n >> s;
    for (int i = 0; i < 26; i++)
        cnt[i] = 1;
    for (int i = 0; i < n; i++)
        ++cnt[s[i] - 'a'];
    int ans = 1;
    for (int i = 0; i < 26; i++)
        ans = (ans * cnt[i]) % mod;
    cout << (ans - 1 + mod) % mod;
    return 0;
}
