#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, ans = 0;
    string s, t;
    map<string, int> str1, str2;
    vector<string> dic;

    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> s;
        str1[s] ++;
        dic.push_back(s);
    }
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        cin >> t;
        str2[t] ++;
        dic.push_back(t);
    }

    ans = 0;
    for ( int i = 0; i < n+m; i++ ) {
        ans = max(ans, str1[dic[i]] - str2[dic[i]]);
    }

    cout << ans << endl;
    return (0);
}