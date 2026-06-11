#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s, t, s_cp;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s_cp = s;
    replace(s_cp.begin(), s_cp.end(), '?', 'a');

    vector<string> matches;
    rep(i, n - m + 1) {
        string a = s.substr(i, m);
        bool matched = true;
        rep(j, m) if (a[j] != '?' && a[j] != t[j]) matched = false;

        if (matched)
            matches.push_back(s_cp.substr(0, i) + t + s_cp.substr(i + m));
    }

    if (matches.size() == 0)
        cout << "UNRESTORABLE" << endl;
    else {
        sort(matches.begin(), matches.end());
        cout << matches[0] << endl;
    }
    return 0;
}
