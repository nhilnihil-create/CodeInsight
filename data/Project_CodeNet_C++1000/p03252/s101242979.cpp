#include <bits/stdc++.h>
using namespace std;


void solve () {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    vector<int> b(26), a(26);
    for (int i = 0; i < n; i++) {
        b[t[i] - 'a']++;
        a[s[i] - 'a']++;
        if(a[s[i] - 'a'] != b[t[i] - 'a']) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
