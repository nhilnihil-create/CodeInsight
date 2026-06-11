#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int redCnt = 0, blueCnt = 0;
    rep (i, n)
    {
        if (s[i] == '0')
            redCnt++;
        else
            blueCnt++;
    }

    cout << min(redCnt, blueCnt) * 2 << endl;
    return 0;
}