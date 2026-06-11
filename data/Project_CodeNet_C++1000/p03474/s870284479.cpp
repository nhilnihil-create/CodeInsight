#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    int c = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '-' && i != a)
        {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] != '-' && i == a)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}