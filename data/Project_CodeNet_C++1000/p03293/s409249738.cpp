#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string rotation(string s, int times)
{
    if (times < 0)
    {
        return s;
    }

    return s.substr(s.length() - times, times) + s.substr(0, s.length() - times);
}

int main()
{
    string S, T;
    cin >> S >> T;

    for (int i = 0; i < S.length(); i++)
    {
        if (rotation(S, i) == T)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}