#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[5];
    cin >> s;
    if (s[0]==s[1] && s[1]==s[2]) puts("Yes");
    else if (s[1]==s[2] && s[2]==s[3]) puts("Yes");
    else puts("No");
}