#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] && s[i] == '0') {
            s[i] = '1';
            ans++;
        }
        else if (s[i] == s[i - 1] && s[i] == '1') {
            s[i] = '0';
            ans++;
        }
    }

    cout << ans << endl;
}