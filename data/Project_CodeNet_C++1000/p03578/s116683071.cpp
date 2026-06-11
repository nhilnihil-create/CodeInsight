#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, m, d, t;
    string ans = "YES";
    scanf("%ld", &n);
    unordered_map<long, long> mp;
    for (long i = 0; i < n; i++) {
        scanf("%ld", &d);
        if (mp.find(d) != mp.end()) {
            mp[d]++;
        } else mp[d] = 1;
    }
    scanf("%ld", &m);
    for (long i = 0; i < m; i++) {
        scanf("%ld", &t);
        if (mp.find(t) != mp.end()) {
            mp[t]--;
            if (mp[t] == 0) mp.erase(t);
        } else ans = "NO";
    }
    cout << ans << endl;
}