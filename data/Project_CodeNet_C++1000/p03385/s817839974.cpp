#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    bool ok = false;
    if(s[0] == 'a' && s[1] == 'b' && s[2] == 'c') ok = true;
    else if(s[0] == 'a' && s[1] == 'c' && s[2] == 'b') ok = true;
    else if(s[0] == 'b' && s[1] == 'a' && s[2] == 'c') ok = true;
    else if(s[0] == 'b' && s[1] == 'c' && s[2] == 'a') ok = true;
    else if(s[0] == 'c' && s[1] == 'a' && s[2] == 'b') ok = true;
    else if(s[0] == 'c' && s[1] == 'b' && s[2] == 'a') ok = true;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}