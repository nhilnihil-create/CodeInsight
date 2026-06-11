#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool check1 = s[0] == s[1] && s[1] == s[2];
    bool check2 = s[1] == s[2] && s[2] == s[3];

    cout << ((check1 || check2) ? "Yes" : "No") << "\n";
}