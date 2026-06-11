#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string s;
    cin >> s;

    int ans = 0, buff = 0;
    bool continue_flag = false;
    
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] == 'A'|| s[i] == 'G' || s[i] == 'C' || s[i] == 'T')
        {
            if (continue_flag) buff++;
            else
            {
                continue_flag = true;
                buff = 1;
            }
        }
        else
        {
            continue_flag = false;
        }
        ans = (ans > buff)? ans : buff;
    }

    cout << ans << endl;
    
    return 0;
}
