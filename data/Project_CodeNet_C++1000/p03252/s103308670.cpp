#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    map<char, char> m;
    vector<bool> used('z' + 1, false);
    for (unsigned int i = 0; i < S.size(); i++)
    {
        char Si = S.at(i), Ti = T.at(i);
        if (m.count(Si) > 0)
        {
            char Tj = m.at(Si);
            if (Ti != Tj)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            if (used.at(Ti))
            {
                cout << "No" << endl;
                return 0;
            }
            m[Si] = Ti;
            used.at(Ti) = true;
        }
    }
    cout << "Yes" << endl;
}