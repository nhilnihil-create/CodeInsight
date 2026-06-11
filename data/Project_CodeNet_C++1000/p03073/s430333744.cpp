#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(i%2==0)
        {
            if(s[i]!='0')
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        else
        {
            if(s[i]!='0')
            {
                y++;
            }
            else
            {
                x++;
            }
        }
    }
    int ans = min(x,y);
    cout << ans << endl;
    return 0;
}
