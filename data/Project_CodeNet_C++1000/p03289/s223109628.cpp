#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    if (s[0] != 'A')
    {
        cout << "WA" << endl;
        return 0;
    }
    int C_cnt = 0;
    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i] == 'C' && i != s.length() - 1 && i != 1)
        {
            C_cnt++;
        }
        else if (0 <= s[i] - 'A' && s[i] - 'Z' <= 0)
        {
            cout << "WA" << endl;
            return 0;
        }
        /* code */
    }
    if (C_cnt == 1)
    {
        cout << "AC" << endl;
    }
    else
    {
        cout << "WA" << endl;
    }
    return 0;
}