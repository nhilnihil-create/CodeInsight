#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for(int bit = 0; bit < 1 << (s.size() - 1); ++bit)
    {
        int sum = s[0] - '0';
        string res;
        res += s[0];
        for(int i = 1; i < s.size(); ++i)
        {
            if(bit & (1 << (i-1)))
            {
                sum += s[i] - '0';
                res += '+';
            } else
            {
                sum -= s[i] - '0';
                res += '-';
            }
            res += s[i];
        }
        
        if(sum == 7)
        {
            cout << res + "=7" << "\n";
            break;
        }
    }

    return 0;
}