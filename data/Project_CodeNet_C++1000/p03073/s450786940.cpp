// https://atcoder.jp/contests/abc124/tasks/abc124_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = s.size();

    for (int first_color = 0; first_color < 2; first_color++)
    {
        int cf = first_color;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int j = s[i] - '0';
            if (j != cf)
            {
                cnt++;
            }
            cf ^= 1;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
