#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int all_cnt = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt_s = 0;
            for (int j = 0; j < s[i].size(); j++)
            {
                if (bit & (1 << s[i][j]))
                {
                    cnt_s++;
                }
            }
            if (cnt_s % 2 == p[i])
            {
                all_cnt++;
            }
        }
        if (all_cnt == m)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}
