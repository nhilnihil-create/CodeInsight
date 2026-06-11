#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8000;
bool dp[MAXN + 1][MAXN + 1];

bool isPoss(vector<int> v, int offset)
{
    if (v.empty())
        return offset == 0;
    int sum = 0;
    for (int x : v)
        sum += x;
    if (sum % 2 != offset % 2)
        return false;
    for (int i = 0; i <= (sum - offset) / 2; i++)
        dp[0][i] = false;
    dp[0][0] = true;
    dp[0][v[0]] = true;
    for (int i = 1; i < (int) v.size(); i++)
    {
        dp[i][0] = true;
        for (int k = 1; k <= (sum - offset) / 2; k++)
        {
            dp[i][k] = dp[i - 1][k] || dp[i - 1][k - v[i]];
        }
    }
    return dp[(int) v.size() - 1][(sum - offset) / 2];
}

int main()
{
    string s;
    int x, y;
    cin >> s >> x >> y;
    if (s.find("T") == string::npos)
    {
        cout << ((int) s.length() == x && y == 0 ? "Yes" : "No") << endl;
    }
    else
    {
        x -= (int) s.find("T");
        s = s.substr((int) s.find("T"));
        bool LR = true;
        int ptr = 0;
        vector<int> leftRight, upDown;
        while (ptr < (int) s.length())
        {
            if (s[ptr] == 'T')
            {
                LR = !LR;
                ptr++;
            }
            else
            {
                int cnt = 0;
                while (ptr < (int) s.length() && s[ptr] == 'F')
                {
                    ptr++;
                    cnt++;
                }
                if (LR)
                    leftRight.push_back(cnt);
                else
                    upDown.push_back(cnt);
            }
        }
        cout << (isPoss(leftRight, abs(x)) && isPoss(upDown, abs(y)) ? "Yes" : "No") << endl;
    }
    return 0;
}
