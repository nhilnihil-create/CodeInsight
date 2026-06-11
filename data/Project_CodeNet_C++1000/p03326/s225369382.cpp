#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int64_t>> xyz(n, {0, 0, 0});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> xyz.at(i).at(j);
        }
    }

    int64_t res = 0;
    for (int p = 0; p < 8; p++)
    {
        vector<int64_t> s;
        for (int i = 0; i < n; i++)
        {
            int64_t v = 0;
            for (int j = 0; j < 3; j++)
            {
                if ((p / (1 << j)) % 2 == 0)
                {
                    v += xyz.at(i).at(j);
                }
                else
                {
                    v -= xyz.at(i).at(j);
                }
            }
            s.push_back(v);
        }
        sort(s.begin(), s.end(), greater<int64_t>());
        int64_t tmp = 0;
        for (int i = 0; i < m; i++)
        {
            tmp += s.at(i);
        }
        if (res < tmp)
        {
            res = tmp;
        }
    }
    cout << res << endl;
}