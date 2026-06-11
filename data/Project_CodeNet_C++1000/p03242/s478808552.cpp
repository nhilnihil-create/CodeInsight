#include <bits/stdc++.h>
using namespace std;
 
signed main () {
    string s;
    cin >> s;
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] == '1')
          	cout << '9';
        else if (s[i] == '9')
          	cout << '1';
        else 
          	cout << s[i];
    }
    cout << '\n';
}