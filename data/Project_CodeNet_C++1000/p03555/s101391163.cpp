#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2;
    cin >> s >> s2;
    reverse(s2.begin(), s2.end());
    if (s2 == s) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}