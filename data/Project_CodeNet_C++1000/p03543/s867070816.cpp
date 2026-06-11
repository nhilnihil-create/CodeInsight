#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0, flag = 0;
    for (int i = 1; i < 4; i++)
    {
        if (s[i - 1] == s[i])
        {
            cnt++;
            if (cnt > 1)
            {
                flag = 1;
                break;
            }
        }
        else
            cnt = 0;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
