#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    string s;
    cin >> s;
    bool ok = false;
    if (s[0] == 'A')
    {
        int count = 0;
        for (int i = 2; i < s.size() - 1; i++)
        {
            if (s[i] == 'C')
            {
                count++;
            }
        }
        if (count == 1)
            ok = true;
    }
    if (ok)
        sort(s.begin(), s.end());
    else
    {
        printf("WA\n");
        return 0;
    }
    s = s.substr(2, s.size());
    rep(i, s.size())
    {
        if (isupper(s[i]))
        {
            printf("WA\n");
            return 0;
        }
    }
    printf("AC\n");
    return 0;
}