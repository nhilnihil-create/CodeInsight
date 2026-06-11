#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (int i  = 0; i < n; i++) {
        cin >> d[i];
    }
    int m;
    cin >> m;
    int t[m];
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[d[i]]++;
    }

    for (int i = 0; i < m; i++) {
        if (mp[t[i]] > 0) {
            mp[t[i]]--;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}