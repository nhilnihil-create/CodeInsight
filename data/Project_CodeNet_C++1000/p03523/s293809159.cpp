#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    regex re("^A?KIHA?BA?RA?$");
    cout << (regex_match(s, re) ? "YES\n" : "NO\n");
    return 0;
}