#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int len = S.length();
    int lenOne = len - 2;
    int lenTwo = len - 1;
    int flag = 0;

    if (S[0] != 'A')
    {
        cout << "WA" << endl;
        return 0;
    }
    else
    {
        for (int i = 2; i <= lenOne; i++)
        {
            if (S[i] == 'C')
                flag += 1;
            if (flag == 2)
                break;
        }

        if (flag != 1)
        {
            cout << "WA" << endl;
            return 0;
        }

        int cnt = 0;
        for (int i = 0; i <= lenTwo; i++)
        {
            if (islower(S[i]) != 0)
                cnt++;
        }
        if (cnt != len - 2)
        {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
}