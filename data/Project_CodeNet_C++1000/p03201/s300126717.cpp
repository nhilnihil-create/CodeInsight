#include <bits/stdc++.h>
using namespace std;

int f (int n) {
    int t = 1;
    while (t <= n) t *= 2;
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& e : a) { cin >> e; mp[e]++; }
    sort(a.rbegin(), a.rend());
    
    int ans = 0;
    for (const auto& x : a) if (mp[x] > 0) {
        int b = f(x) - x;
        if (mp.count(b)) if (mp[b] > 0) {
            if (x != b) {
                ans++; mp[x]--; mp[b]--;
            } else if (mp[b] > 1) {
                ans++; mp[x]--; mp[b]--;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}