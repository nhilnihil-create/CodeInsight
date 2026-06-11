#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using Graph = vector<vector<int>>;
using ll = long long;
using p = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(m));
    vector<int> k(m);
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int val;
            cin >> val;
            s[i][j] = val;
        }
    }

    vector<int> p(m);
    rep(i, m)
    {
        cin >> p[i];
    }

    int ans = 0;
    rep(i, (1 << n))
    {
        map<int, int> mp; // 電球につながってるスイッチの中でONになってる数
        // 電球ループ
        rep(j, m)
        {
            if (!mp[j])
                mp[j] = 0;
            int switch_num = k[j];
            rep(k, switch_num)
            {
                if (i & (1 << (s[j][k] - 1)))
                {
                    mp[j]++;
                }
            }
        }

        int light_num = 0;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
            if (itr->second % 2 == p[itr->first])
            {
                light_num++;
            }
        }
        if (light_num == m)
        {
            ans++;
        }
    }
    cout << ans << endl;
}