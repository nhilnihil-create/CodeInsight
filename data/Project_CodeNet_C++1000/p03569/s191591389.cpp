#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    int l = 0,r = s.size() - 1;
    while(l < r)
    {
        if(s[l] == s[r])
        {
            l++;
            r--;
        }
        else if(s[l] == 'x')
        {
            l++;
            ans++;
        }
        else if(s[r] == 'x')
        {
            r--;
            ans++;
        }
        else
        {
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
    
    return 0;
}