#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    s[--b]+=32;
    cout << s;
}
