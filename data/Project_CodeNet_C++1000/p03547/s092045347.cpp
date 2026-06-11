#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
using namespace std;

int main() {
    char s[2];
    cin >> s[0] >> s[1];
    if(s[0] > s[1])
        cout << ">" << endl;
    else if(s[0] == s[1])
        cout << "=" << endl;
    else
        cout << "<" << endl;
}