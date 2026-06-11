#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, m, t;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> d;
        mp[d]++;
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> t;
        mp[t]--;
        if(mp[t] < 0) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
