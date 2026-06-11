#include <bits/stdc++.h>
using namespace std;

int main () {
    int n ; cin >> n;

    set <string> a;
    bool g = 1;
    string s; cin >> s;
    a.emplace(s);
    char l = s[s.size() - 1]; 
    for (int i = 1; i < n; i++) {
        cin >> s;
        if ((s[0] != l) || (a.count(s)))
            g = 0;
        l = s[s.size() - 1];
        a.emplace(s);
    }

    if (g)
        cout << "Yes";
    else
        cout << "No";
}   