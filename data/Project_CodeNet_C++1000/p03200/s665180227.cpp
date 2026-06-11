#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long rez = 0;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') c++;
        else rez += c;
    }
    cout << rez;
    return 0;
}
