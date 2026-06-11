#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();

    string buf = "";
    for (int i = 0; i < len; i++)
    {
        if(s[i] == 'x')continue;
        buf = buf + s[i];
    }
    bool can = true;
    int blen = buf.size();
    for (int i = 0; i <= blen; i++)
    {
        if(buf[i] != buf[blen - i - 1])can = false;
    }
    if(can)
    {
        int ans = 0;
        for (int i = 0; i < len / 2; i++)
        {
            if(s[i] != s[len - 1 - i])
            {
                if(s[i] == 'x')
                {
                    s.insert(len - i, "x");
                }
                if(s[len - 1 - i] == 'x')
                {
                    s.insert(i, "x");
                }
                len++;ans++;
            }
            //cout << s << " " << ans << endl;
        }
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
}