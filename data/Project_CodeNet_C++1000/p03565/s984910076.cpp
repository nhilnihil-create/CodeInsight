#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    string s, t;
    cin >> s >> t;
    int _s = s.size(), _t = t.size();
    if (_s < _t) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    priority_queue<string, vector<string>, greater<string>> ans;
    for (int i = 0; i + _t <= _s; i++) {
        string x = s;
        bool flag = false;
        for (int j = 0; j < _t; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                flag = true;
                break;
            } else {
                x[i + j] = t[j];
            }
        }
        if (flag) continue;
        for (int k = 0; k < _s; k++) {
            if (x[k] == '?') {
                x[k] = 'a';
            }
        }
        ans.push(x);
    }
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    } else {
        cout << ans.top() << endl;
        return 0;
    }
}