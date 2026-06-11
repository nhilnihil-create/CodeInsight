#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    string w;
    char c;
    cin >> w;
    s.insert(w);
    c = w.at(w.size() - 1);
    for (int i = 1; i < n; i++) {
        string x;
        cin >> x;
        if (s.find(x) == s.end() && x.at(0) == c) {
            s.insert(x);
            c = x.at(x.size() - 1);
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}