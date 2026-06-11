#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s[2];
    cin >> s[0] >> s[1];

    if((s[0][0] == s[1][2])
        && (s[0][1] == s[1][1])
        && (s[0][2] == s[1][0]))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
