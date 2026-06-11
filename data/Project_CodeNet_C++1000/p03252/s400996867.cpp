#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    string s, t;
    cin  >> s >> t;
    map<char, char> mp, rmp;
    bool flag = true;
    rep(i, 0, s.size()) {
        if (mp.count(s[i])) {
            if (mp[s[i]] != t[i]) {
                flag = false;
            }
        } else {
            mp[s[i]] = t[i];
        }
        if (rmp.count(t[i])) {
            if (rmp[t[i]] != s[i]) {
                flag = false;
            }
        } else {
            rmp[t[i]] = s[i];
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
