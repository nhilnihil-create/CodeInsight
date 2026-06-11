#include <bits/stdc++.h>
using namespace std;

void f(int index, string a, vector<string> &t) {
    if (index == 9) {
        t.push_back(a);
        return;
    }
    
    if (a.at(index) == 'A') {
        string s1 = a, s2 = a;
        s1.at(index) = '0';
        f(index + 1, s1, t);
        f(index + 1, s2, t);
    }
    else f(index + 1, a, t);
}

int main() {
    string s;
    cin >> s;
    vector<string> t;
    
    f(0, "AKIHABARA", t);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (int)t.at(i).size(); j++) if (t.at(i).at(j) == '0') t.at(i).erase(t.at(i).begin() + j);
    }
    
    for (int i = 0; i < (int)t.size(); i++) {
        if (s == t.at(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}