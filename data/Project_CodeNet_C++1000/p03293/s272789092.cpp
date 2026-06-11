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
    string s, t;
    cin >> s >> t;
    for (size_t i = 0; i < s.length(); i++)
    {
        string ss = "";
        ss += s[s.length() - 1];
        for (size_t j = 0; j < s.length() - 1; j++)
        {
            ss += s[j];
            /* code */
        }
        if (ss == t)
        {
            cout << "Yes" << endl;
            return 0;
        }
        s = ss;
    }
    cout << "No" << endl;

    return 0;
}