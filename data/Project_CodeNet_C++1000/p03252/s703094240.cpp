#include <bits/stdc++.h>
using namespace std;

signed main () {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    map < char, char > assigned;
    bool fucked = 0;
    for (int i = 0; i < n; ++i) {
        if (assigned.find(s[i]) == assigned.end())
            assigned[s[i]] = t[i];
        else if (assigned[s[i]] != t[i])
            fucked = 1;
    }
    assigned.clear();
    for (int i = 0; i < n; ++i) {
        if (assigned.find(t[i]) == assigned.end())
            assigned[t[i]] = s[i];
        else if (assigned[t[i]] != s[i])
            fucked = 1;
    }
    if (!fucked)
        cout << "Yes\n";
    else
        cout << "No\n";
}
