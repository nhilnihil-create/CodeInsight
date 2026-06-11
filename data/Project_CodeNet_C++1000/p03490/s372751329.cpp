//https://ykmaku.hatenablog.com/entry/2018/08/30/181652
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const ll MAXN = 8020;
string s;
int x, y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    cin >> x >> y;

    vector<int> t;
    int cnt = 0;
    //文字列を変形する
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'T')
        {
            if (cnt != 0)
                t.push_back(cnt);
            t.push_back(0);
            cnt = 0;
        }
        else
        {
            cnt++;
            if (i == s.size() - 1)
                t.push_back(cnt);
        }
    }

    bool dp_x[MAXN][MAXN * 2] = {false}, dp_y[MAXN][MAXN * 2] = {false};
    dp_x[0][8000] = true;
    dp_y[0][8000] = true;

    bool flag = false;
    bool xy = true; // trueならx軸について見ている
    int cnt_x = 0, cnt_y = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == 0)
        {
            xy = !xy;
        }
        else if (xy)
        {
            cnt_x++;
            for (int j = 0; j < MAXN * 2; j++)
            {
                if (dp_x[cnt_x - 1][j])
                {
                    if (j + t[i] < MAXN * 2)
                        dp_x[cnt_x][j + t[i]] = true;
                    if (j - t[i] >= 0 && flag)
                        dp_x[cnt_x][j - t[i]] = true;
                }
            }
        }
        else if (!xy)
        {
            cnt_y++;
            for (int j = 0; j < MAXN * 2; j++)
            {
                if (dp_y[cnt_y - 1][j])
                {
                    if (j + t[i] < MAXN * 2)
                        dp_y[cnt_y][j + t[i]] = true;
                    if (j - t[i] >= 0)
                        dp_y[cnt_y][j - t[i]] = true;
                }
            }
        }

        if (!flag)
            flag = true;
    }

    cout << ((dp_x[cnt_x][x + 8000] && dp_y[cnt_y][y + 8000]) ? "Yes" : "No") << endl;

    return 0;
}
