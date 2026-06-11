#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main()
{
    string s;
    cin >> s;

    int l,r;
    l=0;
    r=s.length()-1;

    int ans = 0;
    while(l<r)
    {
        if (s[l]==s[r])
        {
            l=l+1;
            r=r-1;
        }
        else
        {
            if (s[l]=='x')
            {
                l=l+1;
                ans++;
            }
            else if (s[r]=='x')
            {
                r=r-1;
                ans++;
            }
            else
            {
                ans = -1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
