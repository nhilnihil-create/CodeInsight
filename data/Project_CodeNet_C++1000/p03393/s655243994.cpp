#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    string ans;
    if (S.size() < 26)
    {
        vector<int> dic(26, 0);
        for (int i = 0; i < S.size(); i++)
        {
            int val = (int)(S.at(i) - 'a');
            dic.at(val)++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (dic.at(j) == 0)
            {
                ans = S + (char)(j + (int)'a');
                break;
            }
        }
    }
    else
    {
        vector<int> dic(26, 0);

        int p = S.size() - 1;
        dic.at((int)(S.at(p) - 'a'))++;

        for (int i = S.size() - 2; i >= 0; i--)
        {
            int val = (int)(S.at(i) - 'a');
            for (int j = val; j < 26; j++)
            {
                if (dic.at(j) > 0)
                {
                    p = i;
                    break;
                }
            }

            if (p == i)
            {
                break;
            }

            dic.at(val)++;
        }

        if (p == S.size() - 1)
        {
            ans = "-1";
        }
        else
        {
            int val;
            for (int i = (int)(S.at(p) - 'a'); i < 26; i++)
            {
                if (dic.at(i) > 0)
                {
                    val = i;
                    break;
                }
            }
            ans = S.substr(0, p) + (char)(val + (int)'a');
        }
    }

    cout << ans << endl;

    return 0;
}