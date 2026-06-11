#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - i);
        vector<int> cnt(26, 0);
        for (char c: a) {
            cnt[c - 'a']++;
        }
        int cur = 0;
        for (char c: b) {
            if (cnt[c - 'a']) cur++;
            cnt[c - 'a'] = 0;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}