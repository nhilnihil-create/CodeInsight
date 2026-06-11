#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i, cnt=0;
    cin >> s;
    if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
