#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;
    long ans = 0;
    int while_cnt = 0;
    rep(i, S.size())
    {
        if (S.at(i) == 'W')
        {
            ans += i - while_cnt;
            while_cnt++;
        }
    }

    cout << ans << endl;
    return 0;
}