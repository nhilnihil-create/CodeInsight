 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

map<int, int>mp;


signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(rall(a));
    for (auto it : a)
        mp[it]++;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int c = 1;
        while (c <= a[i])
            c *= 2;
        int nd = c - a[i];
        if (mp[nd] > 0 && mp[a[i]] > 0 && a[i] != nd) {
            mp[nd]--;
            mp[a[i]]--;
            ans++;
        }
        if (nd == a[i] && mp[a[i]] >= 2) {
            mp[nd]--;
            mp[a[i]]--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
