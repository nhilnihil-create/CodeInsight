#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    string t = "AKIHABARA";
    int idx = 0;
    bool flag = true;

    rep(i, t.size()) {
        if (s[idx] != t[i] && t[i] == 'A')
            continue;
        else if (s[idx] != t[i]) {
            flag = false;
            break;
        }
        ++idx;
    }

    if (idx < s.size())
        flag = false;

    flag ? cout << "YES" : cout << "NO";
    cout << endl;

    return 0;
}