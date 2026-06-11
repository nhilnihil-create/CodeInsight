#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int c1 = 0, c2 = 0, c3 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if(s[0] == 'B')
        {
            if(s[s.size() - 1] == 'A')
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        else
        {
            if(s[s.size() - 1] == 'A')
            {
                c3++;
            }
        }

        for (int j = 0; j < (int)s.size() - 1; j++)
        {
            if(s[j] == 'A' && s[j + 1] == 'B')ans++;
        }
        
    }

    if(c1 == 0)
    {
        ans += min(c2, c3);
    }
    else
    {
        if(c2 + c3 > 0)
        {
            ans += min(c2, c3) + c1;
        }
        else
        {
            ans += c1 - 1;
        }
        
    }
    

    cout << ans << endl;
}