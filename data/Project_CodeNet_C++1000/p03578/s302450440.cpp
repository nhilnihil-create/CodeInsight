#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int n, m;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        mp[e]++;
    }
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int e;
        cin >> e;
        mp[e]--;
    }
    
    bool ok = true;
    for (const auto &e : mp) {
        ok &= (e.second >= 0);
    }
    
    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    
    return 0;
}