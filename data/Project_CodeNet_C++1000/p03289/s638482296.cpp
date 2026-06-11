#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool f = 0, lc = 1;
    int c = 0;
    if (s[0] == 'A')
        f = 1;
    for (int i = 1; i < (int)s.size(); i++)
    {
        if (s[i] == 'C' && i >= 2 && i != (int)s.size() - 1)
            c++;
        else if (s[i] < 'a')
            lc = 0;
    }
    if ((f && lc) && (c == 1))
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
}