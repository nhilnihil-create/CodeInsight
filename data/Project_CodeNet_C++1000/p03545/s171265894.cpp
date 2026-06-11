#include <bits/stdc++.h>
using namespace std;
string s;
string myans;
void dfs(int total, string ans, int i) {
    if (i >= 4) {
        if (total == 7) {
            myans = ans;
        }
        return;
    }
    int t1 = total + (s[i] - '0');
    string s1 = ans + '+' + s[i];
    dfs(t1, s1, i + 1);
    int t2 = total - (s[i] - '0');
    string s2 = ans + '-' + s[i];
    dfs(t2, s2, i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s += '0';
    string t; t += s[0];
    dfs(s[0] - '0', t, 1);
    cout << myans << "=7";
    return 0;
}
