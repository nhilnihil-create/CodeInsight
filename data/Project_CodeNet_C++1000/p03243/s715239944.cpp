#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    string s; cin >> s;
    if(s[0] == s[1] && s[1] == s[2])cout << s;
    else if(s[0] >= s[1] && s[0] >= s[2]) cout << s[0] << s[0] << s[0];
    else cout << char(s[0] + 1) << char(s[0] + 1) << char(s[0] + 1);
    return 0;
}
