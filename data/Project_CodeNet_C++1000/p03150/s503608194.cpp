#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    string keyence = "keyence";
    string value;

    if (S == keyence)
    {
        cout << "YES" << endl;
        return 0;
    }
    rep(i, S.size())
    {
        for (int j = i + 1; j < S.size(); j++)
        {
            if (S.substr(0, i) + S.substr(j, S.size()) == keyence)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}