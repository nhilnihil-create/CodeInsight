#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool ok = true;
    for(int i = 0; i < a + b + 1; i++)
    {
        if(i == a)
        {
            if(s[i] != '-')
            {
                ok = false;
                break;
            }
        }
        else if(!(s[i] - '0' >= 0 && s[i] - '0' <= 9))
        {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No");

    return 0;
}
