#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s, t, u;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();
    u = s;
    rep(i, ns) if (u[i] == '?') u[i] = 'a';

    vector<string> matches;
    rep(i, ns - nt + 1) {
        string a = s.substr(i, nt);
        bool ok = true;
        rep(j, nt) if (a[j] != '?' && a[j] != t[j]) ok = false;

        if (ok) matches.push_back(u.substr(0, i) + t + u.substr(i + nt));
    }

    if (matches.size() == 0)
        cout << "UNRESTORABLE" << endl;
    else {
        sort(matches.begin(), matches.end());
        cout << matches[0] << endl;
    }
    return 0;
}
