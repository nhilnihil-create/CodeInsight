#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;

int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    s = " " + s;
    bool valid = s[1] == '1' && s[n] == '0';
    for (int i = 1; i <= n - 1; i++)
    {
        if (s[i] != s[n - i])
            valid = false;
    }
    if (valid)
    {
        int cur = 1;
        for (int i = 2; i <= n; i++)
        {
            cout << cur << " " << i << "\n";
            if (s[i - 1] == '1')
                cur = i;
        }
    }
    else
        cout << -1 << endl;
    return 0;
}
