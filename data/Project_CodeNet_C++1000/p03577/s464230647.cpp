#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    cin >> s;
    string f = "FESTIVAL";
    for (int i = 0; i < s.length() - f.length(); i++) {
        cout << s[i];
    }
    cout << endl;
}