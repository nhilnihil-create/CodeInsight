#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }
    int ans = 0;
    for (auto m : mp) {
        ans = max(ans, m.second);
    }
    cout << ans << '\n';
}