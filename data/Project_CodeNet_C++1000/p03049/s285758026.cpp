#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    int r_A = 0,l_B = 0,both = 0,count = 0;
    for(int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        for(int i = 0;i + 1 < s.size();i++)
        {
            if(s[i] == 'A' && s[i + 1] == 'B')
            {
                count++;
                s[i] = 'X';
                s[i + 1] = 'X';
            }
        }
        if(s[0] == 'B' && s[s.size() - 1] == 'A')
        {
            both++;
        }
        else if(s[0] == 'B')
        {
            l_B++;
        }
        else if(s[s.size() - 1] == 'A')
        {
            r_A++;
        }
    }
    if(both == 0)
    {
        cout << count + min(r_A,l_B) << "\n";
    }
    else if(r_A + l_B > 0)
    {
        cout << count + both + min(r_A,l_B) << "\n";
    }
    else
    {
        cout << count + both - 1 << "\n";
    }

    return 0;
}