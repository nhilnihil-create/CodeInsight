#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> ks(m, vector<long long>(n + 1));
    vector<long long> p(m);
    long long ans = 0;
    for (long long i = 0; i < m; i++)
    {
        long long s;
        cin >> ks.at(i).at(0);
        for (int j = 1; j < ks.at(i).at(0) + 1; j++)
        {
            cin >> ks.at(i).at(j);
        }
    }

    for (long long i = 0; i < m; i++)
    {
        cin >> p.at(i);
    }

    for (int bit = 0; bit < (1 << n); ++bit)
    {
        vector<long long> c(m, 0);
        for (int i = 0; i < n; ++i)
        {
            if (bit & (1 << i))
            {
                for (long long k = 0; k < m; k++)
                {
                    for (int j = 1; j < ks.at(k).at(0) + 1; j++)
                    {
                        if (i + 1 == ks.at(k).at(j))
                        {
                            c.at(k)++;
                        }
                    }
                }
            }
        }

        bool flag = true;
        for (long long i = 0; i < m; i++)
        {
            if ((c.at(i) % 2) != p.at(i))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}