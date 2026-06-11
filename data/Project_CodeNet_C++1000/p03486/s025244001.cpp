#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    vector<int> count(26);
    for (auto c : s)
    {
        count.at(c - 'a')++;
    }
    string sp = "";
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int i = 0; i < count.at(c - 'a'); i++)
        {
            sp += c;
        }
    }

    count = vector<int>(26);
    for (auto c : t)
    {
        count.at(c - 'a')++;
    }
    string tp = "";
    for (char c = 'z'; c >= 'a'; c--)
    {
        for (int i = 0; i < count.at(c - 'a'); i++)
        {
            tp += c;
        }
    }
    cout << ((sp < tp) ? "Yes" : "No") << endl;
    return 0;
}
