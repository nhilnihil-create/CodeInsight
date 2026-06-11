#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int findIndex(vector<long long> v, int value)
{
    auto iter = find(v.begin(), v.end(), value);
    size_t index = distance(v.begin(), iter);
    return index;
}

void printImos(vector<vector<int>> imos)
{
    rep(x, imos.size())
    {
        rep(y, imos[0].size())
        {
            cout << imos[x][y];
        }
        cout << endl;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> x, y;
    vector<pair<int, int>> pos(N);

    rep(i, N)
    {
        cin >> pos[i].first >> pos[i].second;
        x.push_back(pos[i].first);
        y.push_back(pos[i].second);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    vector<vector<int>> imos(x.size() + 1, vector<int>(y.size() + 1, 0));
    int H = x.size() + 1;
    int W = y.size() + 1;
    rep(i, N)
    {
        int ix = findIndex(x, pos[i].first);
        int iy = findIndex(y, pos[i].second);
        imos[ix + 1][iy + 1]++;
    }

    rep(i, H) rep(j, W - 1)
    {
        imos[i][j + 1] += imos[i][j];
    }
    rep(j, W) rep(i, H - 1)
    {
        imos[i + 1][j] += imos[i][j];
    }

    vector<pair<int, int>> point;
    rep(i, x.size()) rep(j, y.size())
    {
        point.push_back(make_pair(i, j));
    }
    long long ans = INT64_MAX;
    for (int ru = 0; ru < point.size(); ru++)
    {
        for (int ld = ru + 1; ld < point.size(); ld++)
        {
            int i_ru_x = point[ru].first;
            int i_ru_y = point[ru].second;
            int i_ld_x = point[ld].first;
            int i_ld_y = point[ld].second;
            if (i_ru_x == i_ld_x || i_ru_y == i_ld_y)
                continue;

            if (i_ru_x < i_ld_x)
                swap(i_ru_x, i_ld_x);
            if (i_ru_y < i_ld_y)
                swap(i_ru_y, i_ld_y);

            int point_num = imos[i_ru_x + 1][i_ru_y + 1] - imos[i_ru_x + 1][i_ld_y] - imos[i_ld_x][i_ru_y + 1] + imos[i_ld_x][i_ld_y];
            if (point_num >= K)
            {
                long long area = (x[i_ru_x] - x[i_ld_x]) * (y[i_ru_y] - y[i_ld_y]);
                ans = min(ans, area);
            }
        }
    }

    if (ans == INT64_MAX)
        ans = -1;
    cout << ans << endl;

    return 0;
}